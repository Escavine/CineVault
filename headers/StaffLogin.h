#ifndef STAFFLOGIN
#define STAFFLOGIN // defining the files to prevent class reinterpretation

#include "user.h"
#include "StudentMonitorMenu.h"

namespace StudentMonitor
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;


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
	private: System::Windows::Forms::Label^ emailLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::TextBox^ emailTextbox;
	private: System::Windows::Forms::MaskedTextBox^ passwordTextbox;




	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ exitButton;
	private: System::Windows::Forms::Button^ loginButton;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ issueText;
	private: System::Windows::Forms::RichTextBox^ issuesParagraph;



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
			this->emailLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->emailTextbox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextbox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->issueText = (gcnew System::Windows::Forms::Label());
			this->issuesParagraph = (gcnew System::Windows::Forms::RichTextBox());
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
			// emailLabel
			// 
			this->emailLabel->AutoSize = true;
			this->emailLabel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->emailLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->emailLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->emailLabel->Location = System::Drawing::Point(12, 90);
			this->emailLabel->Name = L"emailLabel";
			this->emailLabel->Size = System::Drawing::Size(41, 19);
			this->emailLabel->TabIndex = 1;
			this->emailLabel->Text = L"Email";
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->passwordLabel->ForeColor = System::Drawing::SystemColors::Control;
			this->passwordLabel->Location = System::Drawing::Point(12, 177);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(67, 19);
			this->passwordLabel->TabIndex = 2;
			this->passwordLabel->Text = L"Password";
			// 
			// emailTextbox
			// 
			this->emailTextbox->BackColor = System::Drawing::Color::Black;
			this->emailTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->emailTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->emailTextbox->ForeColor = System::Drawing::Color::White;
			this->emailTextbox->Location = System::Drawing::Point(16, 112);
			this->emailTextbox->Name = L"emailTextbox";
			this->emailTextbox->Size = System::Drawing::Size(219, 16);
			this->emailTextbox->TabIndex = 3;
			this->emailTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &StaffLogin::passwordTextbox_KeyDown);
			// 
			// passwordTextbox
			// 
			this->passwordTextbox->BackColor = System::Drawing::Color::Black;
			this->passwordTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->passwordTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->passwordTextbox->ForeColor = System::Drawing::SystemColors::Window;
			this->passwordTextbox->Location = System::Drawing::Point(16, 199);
			this->passwordTextbox->Name = L"passwordTextbox";
			this->passwordTextbox->Size = System::Drawing::Size(219, 16);
			this->passwordTextbox->TabIndex = 4;
			this->passwordTextbox->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &StaffLogin::maskedTextBox1_MaskInputRejected);
			this->passwordTextbox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &StaffLogin::maskedTextBox1_KeyDown);
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
			// exitButton
			// 
			this->exitButton->BackColor = System::Drawing::Color::Transparent;
			this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->exitButton->ForeColor = System::Drawing::Color::White;
			this->exitButton->Location = System::Drawing::Point(124, 251);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(100, 34);
			this->exitButton->TabIndex = 8;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = false;
			this->exitButton->Click += gcnew System::EventHandler(this, &StaffLogin::exitButton_Click);
			// 
			// loginButton
			// 
			this->loginButton->BackColor = System::Drawing::Color::Black;
			this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loginButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->loginButton->ForeColor = System::Drawing::Color::White;
			this->loginButton->Location = System::Drawing::Point(18, 251);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(100, 34);
			this->loginButton->TabIndex = 9;
			this->loginButton->Text = L"Login";
			this->loginButton->UseVisualStyleBackColor = false;
			this->loginButton->Click += gcnew System::EventHandler(this, &StaffLogin::loginButton_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(411, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 19);
			this->label4->TabIndex = 10;
			this->label4->Text = L"StudentMonitor";
			this->label4->Click += gcnew System::EventHandler(this, &StaffLogin::label4_Click);
			// 
			// issueText
			// 
			this->issueText->AutoSize = true;
			this->issueText->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->issueText->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->issueText->ForeColor = System::Drawing::SystemColors::Control;
			this->issueText->Location = System::Drawing::Point(382, 98);
			this->issueText->Name = L"issueText";
			this->issueText->Size = System::Drawing::Size(71, 30);
			this->issueText->TabIndex = 11;
			this->issueText->Text = L"Issues";
			// 
			// issuesParagraph
			// 
			this->issuesParagraph->BackColor = System::Drawing::Color::Black;
			this->issuesParagraph->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->issuesParagraph->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->issuesParagraph->ForeColor = System::Drawing::SystemColors::Menu;
			this->issuesParagraph->Location = System::Drawing::Point(327, 131);
			this->issuesParagraph->Name = L"issuesParagraph";
			this->issuesParagraph->Size = System::Drawing::Size(198, 143);
			this->issuesParagraph->TabIndex = 12;
			this->issuesParagraph->Text = L"Should you face any issues, please get into contact with the administration team "
				L"and they shall assist you.\n\nPlease refer to: administration@eucladian.org.uk";
			this->issuesParagraph->TextChanged += gcnew System::EventHandler(this, &StaffLogin::richTextBox1_TextChanged);
			// 
			// StaffLogin
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(550, 300);
			this->Controls->Add(this->issuesParagraph);
			this->Controls->Add(this->issueText);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->passwordTextbox);
			this->Controls->Add(this->emailTextbox);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->emailLabel);
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
	public: User^ user = nullptr; // global user variable defined from a class header file


	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// terminate the login session, should the user choose to quit the application
		MessageBox::Show("Your session will now be terminated...");
		Application::Exit();

	}

	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ ex)
	{
		String^ email = emailTextbox->Text;
		String^ password = passwordTextbox->Text;


		// Mitigate empty input with selection case
		if (email->Length == 0 || password->Length == 0)
		{
			MessageBox::Show("Please enter email or password");
		}

		try
		{
			// establish a connection with the database
			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=staff;Integrated Security=True;Encrypt=False;";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			// defining the user authentication query
			String^ userAuthenticate = "SELECT * FROM staffMembers WHERE staffEmail=@email AND staffPassword=@password;";

			// binding the email and password variables to the query
			SqlCommand command(userAuthenticate, % sqlConn);
			command.Parameters->AddWithValue("@email", email);
			command.Parameters->AddWithValue("@password", password);

			// executing the query
			SqlDataReader^ reader = command.ExecuteReader();

			if (reader->Read())
			{
				// should the authentication be a success

				user = gcnew User; // defined class of a user (staff member)

				// inserting all relevant details into a class (user.h)
				user->id = reader->GetInt32(0);
				user->name = reader->GetString(1);
				user->surname = reader->GetString(2);
				user->age = reader->GetInt32(3);
				user->gender = reader->GetString(4);
				user->email = reader->GetString(5);
				user->password = reader->GetString(6);

				this->Close();

			}
			else
			{
				// should the details not match with the database
				MessageBox::Show("Email or password is incorrect", "Error with email or password", MessageBoxButtons::OK);
				return;

			}
		}
		catch (Exception^ ex)
		{
			// bug catching 
			MessageBox::Show("SQL Error: " + ex->Message, "Database connection error", MessageBoxButtons::OK);
			return;
		}

	}


	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ ez)
	{



	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ ev)
	{


	}


	private: System::Void passwordTextbox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		// keyboard shortcut
		if (e->KeyValue == (int)Keys::Enter)
		{
			passwordTextbox->Focus();

		}

	}
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {

}
private: System::Void maskedTextBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ ex) 
{
	// keyboard shortcut
	if (ex->KeyValue == (int)Keys::Enter)
	{
		loginButton->PerformClick();

	}
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
};

#endif // finish definition
