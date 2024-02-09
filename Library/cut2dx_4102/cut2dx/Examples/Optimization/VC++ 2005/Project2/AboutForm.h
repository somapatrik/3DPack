#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Project2 {

	/// <summary>
	/// Summary for AboutForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
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
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}
	internal: System::Windows::Forms::Button^  Button1;
	protected: 
	internal: System::Windows::Forms::Label^  Label5;
	internal: System::Windows::Forms::Label^  Label4;
	internal: System::Windows::Forms::Label^  Label3;

	internal: System::Windows::Forms::PictureBox^  PictureBox1;
	internal: System::Windows::Forms::Label^  Label1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->Button1 = (gcnew System::Windows::Forms::Button());
			this->Label5 = (gcnew System::Windows::Forms::Label());
			this->Label4 = (gcnew System::Windows::Forms::Label());
			this->Label3 = (gcnew System::Windows::Forms::Label());
			this->PictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// Button1
			// 
			this->Button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Button1->Location = System::Drawing::Point(161, 160);
			this->Button1->Name = L"Button1";
			this->Button1->Size = System::Drawing::Size(75, 23);
			this->Button1->TabIndex = 13;
			this->Button1->Text = L"Ok";
			this->Button1->UseVisualStyleBackColor = true;
			// 
			// Label5
			// 
			this->Label5->AutoSize = true;
			this->Label5->Location = System::Drawing::Point(198, 121);
			this->Label5->Name = L"Label5";
			this->Label5->Size = System::Drawing::Size(153, 13);
			this->Label5->TabIndex = 12;
			this->Label5->Text = L"contact@optimalprograms.com";
			// 
			// Label4
			// 
			this->Label4->AutoSize = true;
			this->Label4->Location = System::Drawing::Point(198, 97);
			this->Label4->Name = L"Label4";
			this->Label4->Size = System::Drawing::Size(133, 13);
			this->Label4->TabIndex = 11;
			this->Label4->Text = L"www.optimalprograms.com";
			// 
			// Label3
			// 
			this->Label3->AutoSize = true;
			this->Label3->Location = System::Drawing::Point(198, 73);
			this->Label3->Name = L"Label3";
			this->Label3->Size = System::Drawing::Size(190, 13);
			this->Label3->TabIndex = 10;
			this->Label3->Text = L"Copyright 2004-2010 Optimal Programs";
			// 
			// PictureBox1
			// 
			this->PictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"PictureBox1.Image")));
			this->PictureBox1->Location = System::Drawing::Point(12, 12);
			this->PictureBox1->Name = L"PictureBox1";
			this->PictureBox1->Size = System::Drawing::Size(168, 109);
			this->PictureBox1->TabIndex = 8;
			this->PictureBox1->TabStop = false;
			// 
			// Label1
			// 
			this->Label1->AutoSize = true;
			this->Label1->Location = System::Drawing::Point(198, 27);
			this->Label1->Name = L"Label1";
			this->Label1->Size = System::Drawing::Size(92, 13);
			this->Label1->TabIndex = 7;
			this->Label1->Text = L"Cut 2D X example";
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(403, 195);
			this->Controls->Add(this->Button1);
			this->Controls->Add(this->Label5);
			this->Controls->Add(this->Label4);
			this->Controls->Add(this->Label3);
			this->Controls->Add(this->PictureBox1);
			this->Controls->Add(this->Label1);
			this->Name = L"AboutForm";
			this->Text = L"AboutForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->PictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
