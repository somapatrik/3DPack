#pragma once
#include "registerform.h"
#include "aboutform.h"
#include "stdlib.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace optimal2dx;


	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  registerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	public: System::Windows::Forms::ListBox^  lbWaste;
	private: 


	public: System::Windows::Forms::PictureBox^  Picture1;
	public: System::Windows::Forms::TextBox^  tbUtilizedSurface;
	public: System::Windows::Forms::Button^  cbStart;
	public: System::Windows::Forms::Label^  Label7;


	public: System::Windows::Forms::Label^  Label1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private:	optimal2dx::Optimization2DX ^ Optimization2DX1;
				int iteration;

//	private: event EventHandler^ Optimization2DX1_OnIteration;

	public: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lbWaste = (gcnew System::Windows::Forms::ListBox());
			this->Picture1 = (gcnew System::Windows::Forms::PictureBox());
			this->tbUtilizedSurface = (gcnew System::Windows::Forms::TextBox());
			this->cbStart = (gcnew System::Windows::Forms::Button());
			this->Label7 = (gcnew System::Windows::Forms::Label());
			this->Label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->registerToolStripMenuItem, 
				this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// registerToolStripMenuItem
			// 
			this->registerToolStripMenuItem->Name = L"registerToolStripMenuItem";
			this->registerToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->registerToolStripMenuItem->Text = L"Register ...";
			this->registerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::registerToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->aboutToolStripMenuItem->Text = L"About ...";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// lbWaste
			// 
			this->lbWaste->BackColor = System::Drawing::SystemColors::Window;
			this->lbWaste->Cursor = System::Windows::Forms::Cursors::Default;
			this->lbWaste->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbWaste->ForeColor = System::Drawing::SystemColors::WindowText;
			this->lbWaste->ItemHeight = 14;
			this->lbWaste->Location = System::Drawing::Point(333, 57);
			this->lbWaste->Name = L"lbWaste";
			this->lbWaste->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->lbWaste->Size = System::Drawing::Size(97, 186);
			this->lbWaste->TabIndex = 36;
			// 
			// Picture1
			// 
			this->Picture1->BackColor = System::Drawing::SystemColors::Control;
			this->Picture1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Picture1->Cursor = System::Windows::Forms::Cursors::Default;
			this->Picture1->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Picture1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Picture1->Location = System::Drawing::Point(9, 37);
			this->Picture1->Name = L"Picture1";
			this->Picture1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Picture1->Size = System::Drawing::Size(313, 209);
			this->Picture1->TabIndex = 31;
			this->Picture1->TabStop = false;
			// 
			// tbUtilizedSurface
			// 
			this->tbUtilizedSurface->AcceptsReturn = true;
			this->tbUtilizedSurface->BackColor = System::Drawing::SystemColors::Window;
			this->tbUtilizedSurface->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->tbUtilizedSurface->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tbUtilizedSurface->ForeColor = System::Drawing::SystemColors::WindowText;
			this->tbUtilizedSurface->Location = System::Drawing::Point(118, 277);
			this->tbUtilizedSurface->MaxLength = 0;
			this->tbUtilizedSurface->Name = L"tbUtilizedSurface";
			this->tbUtilizedSurface->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tbUtilizedSurface->Size = System::Drawing::Size(101, 20);
			this->tbUtilizedSurface->TabIndex = 29;
			// 
			// cbStart
			// 
			this->cbStart->BackColor = System::Drawing::SystemColors::Control;
			this->cbStart->Cursor = System::Windows::Forms::Cursors::Default;
			this->cbStart->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cbStart->ForeColor = System::Drawing::SystemColors::ControlText;
			this->cbStart->Location = System::Drawing::Point(9, 272);
			this->cbStart->Name = L"cbStart";
			this->cbStart->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->cbStart->Size = System::Drawing::Size(81, 25);
			this->cbStart->TabIndex = 28;
			this->cbStart->Text = L"Start";
			this->cbStart->UseVisualStyleBackColor = false;
			this->cbStart->Click += gcnew System::EventHandler(this, &Form1::cbStart_Click);
			// 
			// Label7
			// 
			this->Label7->BackColor = System::Drawing::SystemColors::Control;
			this->Label7->Cursor = System::Windows::Forms::Cursors::Default;
			this->Label7->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Label7->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Label7->Location = System::Drawing::Point(330, 37);
			this->Label7->Name = L"Label7";
			this->Label7->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Label7->Size = System::Drawing::Size(89, 17);
			this->Label7->TabIndex = 37;
			this->Label7->Text = L"Waste (L x W)";
			// 
			// Label1
			// 
			this->Label1->BackColor = System::Drawing::SystemColors::Control;
			this->Label1->Cursor = System::Windows::Forms::Cursors::Default;
			this->Label1->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Label1->Location = System::Drawing::Point(115, 257);
			this->Label1->Name = L"Label1";
			this->Label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Label1->Size = System::Drawing::Size(111, 17);
			this->Label1->TabIndex = 30;
			this->Label1->Text = L"Utilized Surface (%)";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(442, 24);
			this->menuStrip1->TabIndex = 38;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 315);
			this->Controls->Add(this->lbWaste);
			this->Controls->Add(this->Picture1);
			this->Controls->Add(this->tbUtilizedSurface);
			this->Controls->Add(this->cbStart);
			this->Controls->Add(this->Label7);
			this->Controls->Add(this->Label1);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"Form1";
			this->Text = L"Cut 2D X example";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Picture1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void registerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 RegisterForm ^rf = gcnew(RegisterForm);
				 rf->tbComputerID->Text = Optimization2DX1->ComputerID;
				 if (rf->ShowDialog()== Windows::Forms::DialogResult::OK){
					 Optimization2DX1->RegisterOptimization2DX(rf->tbName->Text, rf->tbSerialNumber->Text);
				 }
			 }
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 AboutForm ^af = gcnew(AboutForm);
				 if (af->ShowDialog()== Windows::Forms::DialogResult::OK){
				 }
		 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 Optimization2DX1 = gcnew Optimization2DX;
			 Optimization2DX1->OnProgress += gcnew optimal2dx::IOptimization2DXEvents_OnProgressEventHandler(this, &Form1::Optimization2DX1_OnProgress);
			 Optimization2DX1->OnFinish += gcnew optimal2dx::IOptimization2DXEvents_OnFinishEventHandler(this, &Form1::Optimization2DX1_OnFinish);
		 }
private: System::Void cbStart_Click(System::Object^  sender, System::EventArgs^  e) {
		cbStart->Enabled = false;

        Optimization2DX1->NumberOfRepositoryPieces = 1;
		Optimization2DX1->SetRepositoryPiece(0, 300, 200, 0, 0, 0, 0, 0, 0, 0);
        Optimization2DX1->BladeWidth = 0;
        Optimization2DX1->OptimizationLevel = 50;
        Optimization2DX1->RandomSeed = 1;

		
        Optimization2DX1->NumberOfDemandPieces = 14;
        Optimization2DX1->SetDemandPiece(0, 60, 40, 1, 0, 0);
        Optimization2DX1->SetDemandPiece(1, 60, 40, 1, 1, 0);
        Optimization2DX1->SetDemandPiece(2, 48, 40, 1, 2, 0);
        Optimization2DX1->SetDemandPiece(3, 60, 53, 1, 3, 0);
        Optimization2DX1->SetDemandPiece(4, 45, 45, 1, 4, 0);
        Optimization2DX1->SetDemandPiece(5, 50, 80, 1, 5, 0);
        Optimization2DX1->SetDemandPiece(6, 45, 75, 1, 6, 0);
        Optimization2DX1->SetDemandPiece(7, 100, 100, 1, 7, 0);
        Optimization2DX1->SetDemandPiece(8, 100, 100, 1, 8, 0);
        Optimization2DX1->SetDemandPiece(9, 90, 90, 1, 9, 0);
        Optimization2DX1->SetDemandPiece(10, 90, 90, 1, 10, 0);
        Optimization2DX1->SetDemandPiece(11, 90, 90, 1, 11, 0);
        Optimization2DX1->SetDemandPiece(12, 110, 110, 1, 12, 0);
        Optimization2DX1->SetDemandPiece(13, 110, 110, 1, 13, 0);

        iteration = 0;

        lbWaste->Items->Clear();

        Optimization2DX1->StartGuillotine();

        cbStart->Enabled = true;
		 }
private: void Optimization2DX1_OnProgress(void) 
		 {
		iteration++;
		 }
private: void Optimization2DX1_OnFinish(void) 
	{

		// if you want to obtain information about all sheets just iterate through all of them
		// sheets are indexed from 0 to TotalNumberOfUtilizedRepositoryPieces
		// usually the first parameter of the methods is the sheet index

		long SheetIndex = 0; // this is the first sheet;


		//int decimal, sign;
		int top_x, top_y, bottom_x, bottom_y, thick;
		int repository_Index, repository_ID, demand_Index, demand_ID, rotated;
		System::Drawing::SizeF text_size;  
		double surf_covered;

		Optimization2DX1->SurfaceCovered(SheetIndex, surf_covered, repository_Index, repository_ID);
		
		tbUtilizedSurface->Text = Convert::ToString(surf_covered);  //_ecvt(Optimization2DX1->SurfaceCovered, 10, &decimal, &sign);
        System::Drawing::Bitmap ^bmp;
		bmp = gcnew System::Drawing::Bitmap(Picture1->Width, Picture1->Height);
		Graphics ^g = Graphics::FromImage(bmp);
		g->Clear(Color::White);

		
		g->DrawRectangle(Pens::Black, 0, 0, 300, 200);
		int NumCuts;
		Optimization2DX1->NumberOfCuttings(SheetIndex, NumCuts, repository_Index, repository_ID);
		for (int i = 0; i < NumCuts; i++){
            Optimization2DX1->GetCut(SheetIndex, i, top_x, top_y, bottom_x, bottom_y, thick, repository_Index, repository_ID);
			g->DrawLine(Pens::Black, top_x, top_y, bottom_x, bottom_y);
		}

		int NumPieces;
		Optimization2DX1->NumberOfUtilizedDemandPieces(SheetIndex, NumPieces, repository_Index, repository_ID);
		for (int i = 0; i < NumPieces; i++){
            Optimization2DX1->GetUtilizedDemandPiece(SheetIndex, i, top_x, top_y, bottom_x, bottom_y, rotated, repository_Index, demand_Index, repository_ID, demand_ID);
			text_size = g->MeasureString(Convert::ToString(System::Math::Abs(bottom_x - top_x)) + "x" + Convert::ToString(System::Math::Abs(bottom_y - top_y)), Font);
			g->DrawString(Convert::ToString(System::Math::Abs(bottom_x - top_x)) + "x" + Convert::ToString(System::Math::Abs(bottom_y - top_y)), Font, Brushes::Black, (bottom_x + top_x) / 2 - text_size.Width / 2, (bottom_y + top_y) / 2 - text_size.Height / 2);
		}
		
		int NumWastes;
		Optimization2DX1->NumberOfWastePieces(SheetIndex, NumWastes, repository_Index, repository_ID);
		for (int i = 0; i < NumWastes; i++){
            Optimization2DX1->GetWastePiece(SheetIndex, i, top_x, top_y, bottom_x, bottom_y, repository_Index, repository_ID);
			lbWaste->Items->Add(Convert::ToString(System::Math::Abs(bottom_x - top_x)) + "x" + Convert::ToString(System::Math::Abs(bottom_y - top_y)));
            text_size = g->MeasureString("w", Font);
			g->DrawString("w", Font, Brushes::Black, (bottom_x + top_x) / 2 - text_size.Width / 2, (bottom_y + top_y) / 2 - text_size.Height / 2);
		}
		Picture1->Image = bmp;
	}

};
}

