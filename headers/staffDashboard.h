#pragma once

namespace StudentMonitor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for staffDashboard
	/// </summary>

	public ref class staffDashboard : public System::Windows::Forms::Form
	{
	private:
		// for displaying the students information
		System::Windows::Forms::DataGridView^ dataGridView1;
	public:

		staffDashboard(void)
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
		~staffDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ homeButton;

	private: System::Windows::Forms::Button^ studentTrackerButton;
	private: System::Windows::Forms::Button^ logoutButton;
	private: System::Windows::Forms::Button^ teachersButton;
	private: System::Windows::Forms::Button^ reportsButton;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(staffDashboard::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->homeButton = (gcnew System::Windows::Forms::Button());
			this->studentTrackerButton = (gcnew System::Windows::Forms::Button());
			this->logoutButton = (gcnew System::Windows::Forms::Button());
			this->teachersButton = (gcnew System::Windows::Forms::Button());
			this->reportsButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(206, 47);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(300, 200);
			this->dataGridView1->TabIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(410, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 19);
			this->label4->TabIndex = 12;
			this->label4->Text = L"StudentMonitor";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(23, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 19);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Staff Dashboard";
			this->label1->Click += gcnew System::EventHandler(this, &staffDashboard::label1_Click);
			// 
			// homeButton
			// 
			this->homeButton->BackColor = System::Drawing::Color::Black;
			this->homeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->homeButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->homeButton->ForeColor = System::Drawing::Color::White;
			this->homeButton->Location = System::Drawing::Point(27, 68);
			this->homeButton->Name = L"homeButton";
			this->homeButton->Size = System::Drawing::Size(100, 34);
			this->homeButton->TabIndex = 14;
			this->homeButton->Text = L"Home";
			this->homeButton->UseVisualStyleBackColor = false;
			this->homeButton->Click += gcnew System::EventHandler(this, &staffDashboard::homeButton_Click);
			// 
			// studentTrackerButton
			// 
			this->studentTrackerButton->BackColor = System::Drawing::Color::Black;
			this->studentTrackerButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->studentTrackerButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->studentTrackerButton->ForeColor = System::Drawing::Color::White;
			this->studentTrackerButton->Location = System::Drawing::Point(27, 108);
			this->studentTrackerButton->Name = L"studentTrackerButton";
			this->studentTrackerButton->Size = System::Drawing::Size(100, 34);
			this->studentTrackerButton->TabIndex = 15;
			this->studentTrackerButton->Text = L"Students";
			this->studentTrackerButton->UseVisualStyleBackColor = false;
			this->studentTrackerButton->Click += gcnew System::EventHandler(this, &staffDashboard::studentTrackerButton_Click);
			// 
			// logoutButton
			// 
			this->logoutButton->BackColor = System::Drawing::Color::Black;
			this->logoutButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->logoutButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->logoutButton->ForeColor = System::Drawing::Color::White;
			this->logoutButton->Location = System::Drawing::Point(27, 232);
			this->logoutButton->Name = L"logoutButton";
			this->logoutButton->Size = System::Drawing::Size(100, 34);
			this->logoutButton->TabIndex = 16;
			this->logoutButton->Text = L"Logout";
			this->logoutButton->UseVisualStyleBackColor = false;
			this->logoutButton->Click += gcnew System::EventHandler(this, &staffDashboard::logoutButton_Click);
			// 
			// teachersButton
			// 
			this->teachersButton->BackColor = System::Drawing::Color::Black;
			this->teachersButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->teachersButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->teachersButton->ForeColor = System::Drawing::Color::White;
			this->teachersButton->Location = System::Drawing::Point(27, 148);
			this->teachersButton->Name = L"teachersButton";
			this->teachersButton->Size = System::Drawing::Size(100, 34);
			this->teachersButton->TabIndex = 17;
			this->teachersButton->Text = L"Teachers";
			this->teachersButton->UseVisualStyleBackColor = false;
			this->teachersButton->Click += gcnew System::EventHandler(this, &staffDashboard::teachersButton_Click);
			// 
			// reportsButton
			// 
			this->reportsButton->BackColor = System::Drawing::Color::Black;
			this->reportsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->reportsButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->reportsButton->ForeColor = System::Drawing::Color::White;
			this->reportsButton->Location = System::Drawing::Point(27, 192);
			this->reportsButton->Name = L"reportsButton";
			this->reportsButton->Size = System::Drawing::Size(100, 34);
			this->reportsButton->TabIndex = 18;
			this->reportsButton->Text = L"Reports";
			this->reportsButton->UseVisualStyleBackColor = false;
			// 
			// staffDashboard
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(550, 300);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->reportsButton);
			this->Controls->Add(this->teachersButton);
			this->Controls->Add(this->logoutButton);
			this->Controls->Add(this->studentTrackerButton);
			this->Controls->Add(this->homeButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"staffDashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &staffDashboard::staffDashboard_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void staffDashboard_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void logoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// should the user choose to logout, then they'll be presented with this message before termination

	dataGridView1->Visible = false;

	MessageBox::Show("Your session will now be terminated...", "Log Out", MessageBoxButtons::OK);
	this->Close();
}

// will display all the students
private: System::Void studentTrackerButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// find database path
	String^ connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=staff;Integrated Security=True;Encrypt=False;";
	SqlConnection^ connection = gcnew SqlConnection(connectionString);

	try {
		// Open the database
		connection->Open();

		// Initiate the query
		SqlCommand^ command = gcnew SqlCommand("SELECT * FROM students", connection);

		// Execute the command
		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
		DataTable^ dataTable = gcnew DataTable();
		dataAdapter->Fill(dataTable);

		// Bind the data to the DataGridView
		dataGridView1->DataSource = dataTable;

		dataGridView1->Visible = true;

	}
	catch (Exception^ ex) {
		// Handle exceptions
		MessageBox::Show("Database connection error: " + ex->Message, "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		// Close the connection in the finally block
		if (connection->State == ConnectionState::Open) {
			connection->Close();
		}
	}
}
private: System::Void homeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Visible = false;

}

private: System::Void teachersButton_Click(System::Object^ sender, System::EventArgs^ e) {
	// find database path
	String^ connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=staff;Integrated Security=True;Encrypt=False;";
	SqlConnection^ connection = gcnew SqlConnection(connectionString);

	try {
		// Open the database
		connection->Open();

		// Initiate the query
		SqlCommand^ command = gcnew SqlCommand("SELECT staffName, staffSurname FROM staffMembers", connection);

		// Execute the command
		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
		DataTable^ dataTable = gcnew DataTable();
		dataAdapter->Fill(dataTable);

		// Bind the data to the DataGridView
		dataGridView1->DataSource = dataTable;

		dataGridView1->Visible = true;

	}
	catch (Exception^ ex) {
		// Handle exceptions
		MessageBox::Show("Database connection error: " + ex->Message, "SQL Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		// Close the connection in the finally block
		if (connection->State == ConnectionState::Open) {
			connection->Close();
		}
	}
}
};
}
