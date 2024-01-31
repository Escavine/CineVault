#pragma once

#ifndef STUDENTMONITORMENU
#define STUDENTMONITORMENU

#include "StaffLogin.h"

namespace StudentMonitor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StudentMonitorMenu
	/// </summary>
	public ref class StudentMonitorMenu : public System::Windows::Forms::Form
	{
	public:
		StudentMonitorMenu(void)
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
		~StudentMonitorMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ buttonOK;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::ComponentModel::IContainer^ components;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StudentMonitorMenu::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(228, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Menu";
			this->label1->Click += gcnew System::EventHandler(this, &StudentMonitorMenu::label1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 10, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(420, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 19);
			this->label4->TabIndex = 11;
			this->label4->Text = L"StudentMonitor";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Black;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(286, 175);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 34);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Student Login";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &StudentMonitorMenu::button2_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->BackColor = System::Drawing::Color::Black;
			this->buttonOK->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonOK->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->buttonOK->ForeColor = System::Drawing::Color::White;
			this->buttonOK->Location = System::Drawing::Point(119, 175);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(124, 34);
			this->buttonOK->TabIndex = 14;
			this->buttonOK->Text = L"Staff Login";
			this->buttonOK->UseVisualStyleBackColor = false;
			this->buttonOK->Click += gcnew System::EventHandler(this, &StudentMonitorMenu::buttonOK_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// StudentMonitorMenu
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(546, 300);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"StudentMonitorMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e) {
		// Perform any necessary actions before closing the form

		// Set the DialogResult property to OK
		this->DialogResult = System::Windows::Forms::DialogResult::OK;

		// Close the form
		this->Close();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

#endif // define the menu