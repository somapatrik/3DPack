using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using optimal2dx;


namespace Project2
{
    public partial class Form1 : Form
    {
        static Optimization2DX  Optimization2DX1;
        //static Optimization2DX Optimization2DX1;
        static int iteration; 
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
             Optimization2DX1 = new Optimization2DX();
			 Optimization2DX1.OnProgress += new IOptimization2DXEvents_OnProgressEventHandler(Optimization2DX1_OnProgress);
			 Optimization2DX1.OnFinish   += new IOptimization2DXEvents_OnFinishEventHandler(Optimization2DX1_OnFinish);
		  }

        private void Optimization2DX1_OnProgress() 
		 {
		        iteration++;
		 }

        private void Optimization2DX1_OnFinish()
        {
           	// if you want to obtain information about all sheets just iterate through all of them
		// sheets are indexed from 0 to TotalNumberOfUtilizedRepositoryPieces
		// usually the first parameter of the methods is the sheet index
        int SheetIndex = 0; // this is the first sheet;

        int top_x, top_y, bottom_x, bottom_y, thick;
        int repository_Index, repository_ID, demand_Index, demand_ID, rotated;
		System.Drawing.SizeF text_size;  
		double surf_covered;

        Optimization2DX1.SurfaceCovered(SheetIndex, out surf_covered, out repository_Index, out repository_ID);
		
		tbUtilizedSurface.Text = Convert.ToString(surf_covered);  
        System.Drawing.Bitmap bmp;
		bmp = new System.Drawing.Bitmap(Picture1.Width, Picture1.Height);
		Graphics g = Graphics.FromImage(bmp);
		g.Clear(Color.White);

		
		g.DrawRectangle(Pens.Black, 0, 0, 300, 200);
		int NumCuts;
        Optimization2DX1.NumberOfCuttings(SheetIndex, out NumCuts, out repository_Index, out repository_ID);
		for (int i = 0; i < NumCuts; i++){
            Optimization2DX1.GetCut(SheetIndex, i, out  top_x, out  top_y, out bottom_x, out bottom_y, out thick, out repository_Index, out repository_ID);
            g.DrawLine(Pens.Black, top_x, top_y, bottom_x, bottom_y);
		}

		int NumPieces;
        Optimization2DX1.NumberOfUtilizedDemandPieces(SheetIndex, out NumPieces, out  repository_Index, out  repository_ID);
		for (int i = 0; i < NumPieces; i++){
            Optimization2DX1.GetUtilizedDemandPiece(SheetIndex, i, out top_x, out top_y, out bottom_x, out bottom_y, out rotated, out repository_Index, out demand_Index, out repository_ID, out demand_ID);
            text_size = g.MeasureString(Convert.ToString(System.Math.Abs(bottom_x - top_x)) + "x" + Convert.ToString(System.Math.Abs(bottom_y - top_y)), Font);
            g.DrawString(Convert.ToString(System.Math.Abs(bottom_x - top_x)) + "x" + Convert.ToString(System.Math.Abs(bottom_y - top_y)), Font, Brushes.Black, (bottom_x + top_x) / 2 - text_size.Width / 2, (bottom_y + top_y) / 2 - text_size.Height / 2);
		}
		
		int NumWastes;
        Optimization2DX1.NumberOfWastePieces(SheetIndex, out NumWastes, out  repository_Index, out  repository_ID);
		for (int i = 0; i < NumWastes; i++){
            Optimization2DX1.GetWastePiece(SheetIndex, i, out top_x, out  top_y, out bottom_x, out bottom_y, out repository_Index, out repository_ID);
            lbWaste.Items.Add(Convert.ToString(System.Math.Abs(bottom_x - top_x)) + "x" + Convert.ToString(System.Math.Abs(bottom_y - top_y)));
            text_size = g.MeasureString("w", Font);
            g.DrawString("w", Font, Brushes.Black, (bottom_x + top_x) / 2 - text_size.Width / 2, (bottom_y + top_y) / 2 - text_size.Height / 2);
		}
		Picture1.Image = bmp;
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void registerToolStripMenuItem_Click(object sender, EventArgs e)
        {
             RegisterForm rf = new RegisterForm();
		     rf.tbComputerID.Text = Optimization2DX1.ComputerID;
			 if (rf.ShowDialog()== DialogResult.OK){
				 Optimization2DX1.RegisterOptimization2DX(rf.tbName.Text, rf.tbSerialNumber.Text);
			 }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AboutForm af = new AboutForm();
            if (af.ShowDialog() == DialogResult.OK)
            {
            }
        }

        private void bStart_Click(object sender, EventArgs e)
        {
            bStart.Enabled = false;

            Optimization2DX1.NumberOfRepositoryPieces = 1;
            Optimization2DX1.SetRepositoryPiece(0, 300, 200, 0, 0, 0, 0, 0, 0, 0);
            Optimization2DX1.BladeWidth = 0;
            Optimization2DX1.OptimizationLevel = 50;
            Optimization2DX1.RandomSeed = 1;

            Optimization2DX1.NumberOfDemandPieces = 14;
            Optimization2DX1.SetDemandPiece( 0,  60,  40, 1,  0, 0);
            Optimization2DX1.SetDemandPiece( 1,  60,  40, 1,  1, 0);
            Optimization2DX1.SetDemandPiece( 2,  48,  40, 1,  2, 0);
            Optimization2DX1.SetDemandPiece( 3,  60,  53, 1,  3, 0);
            Optimization2DX1.SetDemandPiece( 4,  45,  45, 1,  4, 0);
            Optimization2DX1.SetDemandPiece( 5,  50,  80, 1,  5, 0);
            Optimization2DX1.SetDemandPiece( 6,  45,  75, 1,  6, 0);
            Optimization2DX1.SetDemandPiece( 7, 100, 100, 1,  7, 0);
            Optimization2DX1.SetDemandPiece( 8, 100, 100, 1,  8, 0);
            Optimization2DX1.SetDemandPiece( 9,  90,  90, 1,  9, 0);
            Optimization2DX1.SetDemandPiece(10,  90,  90, 1, 10, 0);
            Optimization2DX1.SetDemandPiece(11,  90,  90, 1, 11, 0);
            Optimization2DX1.SetDemandPiece(12, 110, 110, 1, 12, 0);
            Optimization2DX1.SetDemandPiece(13, 110, 110, 1, 13, 0);

            iteration = 0;

            lbWaste.Items.Clear();

            Optimization2DX1.StartGuillotine();

            bStart.Enabled = true;
        }    

       
        
    }
}