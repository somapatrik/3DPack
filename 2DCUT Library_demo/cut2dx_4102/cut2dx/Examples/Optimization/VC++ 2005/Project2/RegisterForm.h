#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Project2 {

	/// <summary>
	/// Summary for RegisterForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
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
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	internal: System::Windows::Forms::Button^  bCancel;
	protected: 
	public: System::Windows::Forms::Button^  bRegister;
	internal: 
	public: System::Windows::Forms::TextBox^  tbSerialNumber;
	public: System::Windows::Forms::TextBox^  tbComputerID;
	public: System::Windows::Forms::TextBox^  tbName;
	public: System::Windows::Forms::Label^  Label4;
	public: System::Windows::Forms::Label^  Label3;
	public: System::Windows::Forms::Label^  Label2;

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
			this->bCancel = (gcnew System::Windows::Forms::Button());
			this->bRegister = (gcnew System::Windows::Forms::Button());
			this->tbSerialNumber = (gcnew System::Windows::Forms::TextBox());
			this->tbComputerID = (gcnew System::Windows::Forms::TextBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->Label4 = (gcnew System::Windows::Forms::Label());
			this->Label3 = (gcnew System::Windows::Forms::Label());
			this->Label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// bCancel
			// 
			this->bCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->bCancel->Location = System::Drawing::Point(220, 185);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(75, 23);
			this->bCancel->TabIndex = 26;
			this->bCancel->Text = L"Cancel";
			this->bCancel->UseVisualStyleBackColor = true;
			// 
			// bRegister
			// 
			this->bRegister->BackColor = System::Drawing::SystemColors::Control;
			this->bRegister->Cursor = System::Windows::Forms::Cursors::Default;
			this->bRegister->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->bRegister->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bRegister->ForeColor = System::Drawing::SystemColors::ControlText;
			this->bRegister->Location = System::Drawing::Point(58, 185);
			this->bRegister->Name = L"bRegister";
			this->bRegister->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->bRegister->Size = System::Drawing::Size(81, 25);
			this->bRegister->TabIndex = 25;
			this->bRegister->Text = L"Register";
			this->bRegister->UseVisualStyleBackColor = false;
			// 
			// tbSerialNumber
			// 
			this->tbSerialNumber->AcceptsReturn = true;
			this->tbSerialNumber->BackColor = System::Drawing::SystemColors::Window;
			this->tbSerialNumber->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->tbSerialNumber->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tbSerialNumber->ForeColor = System::Drawing::SystemColors::WindowText;
			this->tbSerialNumber->Location = System::Drawing::Point(12, 143);
			this->tbSerialNumber->MaxLength = 0;
			this->tbSerialNumber->Name = L"tbSerialNumber";
			this->tbSerialNumber->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tbSerialNumber->Size = System::Drawing::Size(331, 20);
			this->tbSerialNumber->TabIndex = 21;
			// 
			// tbComputerID
			// 
			this->tbComputerID->AcceptsReturn = true;
			this->tbComputerID->BackColor = System::Drawing::SystemColors::Window;
			this->tbComputerID->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->tbComputerID->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tbComputerID->ForeColor = System::Drawing::SystemColors::WindowText;
			this->tbComputerID->Location = System::Drawing::Point(12, 87);
			this->tbComputerID->MaxLength = 0;
			this->tbComputerID->Name = L"tbComputerID";
			this->tbComputerID->ReadOnly = true;
			this->tbComputerID->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tbComputerID->Size = System::Drawing::Size(331, 20);
			this->tbComputerID->TabIndex = 20;
			// 
			// tbName
			// 
			this->tbName->AcceptsReturn = true;
			this->tbName->BackColor = System::Drawing::SystemColors::Window;
			this->tbName->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->tbName->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tbName->ForeColor = System::Drawing::SystemColors::WindowText;
			this->tbName->Location = System::Drawing::Point(12, 31);
			this->tbName->MaxLength = 0;
			this->tbName->Name = L"tbName";
			this->tbName->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tbName->Size = System::Drawing::Size(331, 20);
			this->tbName->TabIndex = 19;
			this->tbName->Text = L"Your company name here ...";
			// 
			// Label4
			// 
			this->Label4->BackColor = System::Drawing::SystemColors::Control;
			this->Label4->Cursor = System::Windows::Forms::Cursors::Default;
			this->Label4->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Label4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Label4->Location = System::Drawing::Point(12, 127);
			this->Label4->Name = L"Label4";
			this->Label4->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Label4->Size = System::Drawing::Size(81, 17);
			this->Label4->TabIndex = 24;
			this->Label4->Text = L"Serial Number";
			// 
			// Label3
			// 
			this->Label3->BackColor = System::Drawing::SystemColors::Control;
			this->Label3->Cursor = System::Windows::Forms::Cursors::Default;
			this->Label3->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Label3->Location = System::Drawing::Point(12, 71);
			this->Label3->Name = L"Label3";
			this->Label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Label3->Size = System::Drawing::Size(65, 17);
			this->Label3->TabIndex = 23;
			this->Label3->Text = L"ComputerID";
			// 
			// Label2
			// 
			this->Label2->BackColor = System::Drawing::SystemColors::Control;
			this->Label2->Cursor = System::Windows::Forms::Cursors::Default;
			this->Label2->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Label2->Location = System::Drawing::Point(12, 15);
			this->Label2->Name = L"Label2";
			this->Label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Label2->Size = System::Drawing::Size(57, 17);
			this->Label2->TabIndex = 22;
			this->Label2->Text = L"Name";
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(355, 226);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->bRegister);
			this->Controls->Add(this->tbSerialNumber);
			this->Controls->Add(this->tbComputerID);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->Label4);
			this->Controls->Add(this->Label3);
			this->Controls->Add(this->Label2);
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
