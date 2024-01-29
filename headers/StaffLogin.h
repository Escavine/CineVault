#pragma once
#include <vcclr.h>


namespace StudentMonitor
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Data::Sql;
	using namespace System::Data::SqlTypes;

	/// <summary>
	/// Summary for StaffLogin
	/// </summary>
	public ref class StaffLogin : public System::Windows::Forms::Form {
	public:
		StaffLogin(void)
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
		~StaffLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StaffLogin::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(14, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Staff Login";
			this->label1->Click += gcnew System::EventHandler(this, &StaffLogin::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(12, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Email";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->Location = System::Drawing::Point(12, 177);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Password";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Black;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(16, 112);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(219, 16);
			this->textBox1->TabIndex = 3;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &StaffLogin::textBox1_KeyDown);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->BackColor = System::Drawing::Color::Black;
			this->maskedTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->maskedTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->maskedTextBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->maskedTextBox1->Location = System::Drawing::Point(16, 199);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(219, 16);
			this->maskedTextBox1->TabIndex = 4;
			this->maskedTextBox1->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &StaffLogin::maskedTextBox1_MaskInputRejected);
			this->maskedTextBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &StaffLogin::maskedTextBox1_KeyDown);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->ForeColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(16, 134);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(219, 2);
			this->panel1->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->ForeColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(16, 221);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(219, 2);
			this->panel2->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(124, 251);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 34);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &StaffLogin::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(18, 251);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 34);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &StaffLogin::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(436, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 19);
			this->label4->TabIndex = 10;
			this->label4->Text = L"StudentMonitor";
			this->label4->Click += gcnew System::EventHandler(this, &StaffLogin::label4_Click);
			// 
			// StaffLogin
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(562, 339);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"StaffLogin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ email = textBox1->Text;
		String^ password = maskedTextBox1->Text;


		// If input is empty
		if (email->Length == 0 || password->Length == 0)
		{
			MessageBox::Show("Please enter email or password");
		}

		try
		{
			// connect to the database
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=staff;Integrated Security=True;Encrypt=False;Trust Server Certificate=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// defining the query
			String^ userAuthenticate = "SELECT * FROM staff WHERE email=@staffEmail AND password=@staffPassword";

			SqlCommand command(userAuthenticate, % sqlConn);
			command.Parameters->AddWithValue("@staffEmail", email);
			command.Parameters->AddWithValue("@staffPassword", password);

			SqlDataReader^ reader = command.ExecuteReader();

			if (reader->Read())
			{
				this->Close();
			}
			else
			{
				MessageBox::Show("Email or password is incorrect", "Error with email or password", MessageBoxButtons::OK);

			}
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Error loading database", "Database connection error", MessageBoxButtons::OK);
			return;
		}

	}


	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e)
	{



	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e)
	{


	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("Your session will now be terminated...");
		Application::Exit();

	}

	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
		{
			maskedTextBox1->Focus();

		}

	}
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {

}
private: System::Void maskedTextBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Enter)
	{
		button1->PerformClick();

	}
}
};
};


