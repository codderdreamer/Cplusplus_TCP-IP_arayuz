#pragma once
#include "Server.h"
#include <string>
#include <sstream>
//#include <iostream>
#include <SQLDatabase.h>


namespace ServerMCinterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Timers;
	using namespace System::Text;
	using namespace System::Data::Sql;
	using namespace Finisar::SQLite;

	const char* dir = "C:\\Sqlite_server\\Server\\ServerMCinterface\\database\\ClientsData.db";
	sqlite3* DB;
	Config config;
	Server Serv;
#pragma region Windows Form Definition
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			CheckForIllegalCrossThreadCalls = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: System::Windows::Forms::TextBox^ textBox1;
	public: System::Windows::Forms::TextBox^ textBox2;
	public: System::Windows::Forms::TextBox^ textBox3;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ label12;
	public: System::Windows::Forms::TextBox^ TNumberOfClients;
	public: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::CheckBox^ checkHostName;
	public: System::Windows::Forms::CheckBox^ checkService;
	public: System::Windows::Forms::CheckBox^ checkIpAddress;
	public: System::Windows::Forms::CheckBox^ checkBiosVersion;
	public: System::Windows::Forms::CheckBox^ checkTotalPysicalMemory;
	public: System::Windows::Forms::CheckBox^ checkSystemManufacturer;
	public: System::Windows::Forms::CheckBox^ checkOsName;
	public: System::Windows::Forms::CheckBox^ checkEthernet;
	public: System::Windows::Forms::GroupBox^ groupBox1;
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	public: System::Windows::Forms::CheckBox^ checkWifi;

	public: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	public: System::ComponentModel::BackgroundWorker^ backgroundWorker2;
	public: System::ComponentModel::IContainer^ components;

	protected:

	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->TNumberOfClients = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkHostName = (gcnew System::Windows::Forms::CheckBox());
			this->checkService = (gcnew System::Windows::Forms::CheckBox());
			this->checkIpAddress = (gcnew System::Windows::Forms::CheckBox());
			this->checkBiosVersion = (gcnew System::Windows::Forms::CheckBox());
			this->checkTotalPysicalMemory = (gcnew System::Windows::Forms::CheckBox());
			this->checkSystemManufacturer = (gcnew System::Windows::Forms::CheckBox());
			this->checkOsName = (gcnew System::Windows::Forms::CheckBox());
			this->checkEthernet = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkWifi = (gcnew System::Windows::Forms::CheckBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 371);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(68, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(15, 399);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(230, 22);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(15, 427);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(230, 22);
			this->textBox3->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(89, 374);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Winsock Error Code";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(49, 497);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(120, 17);
			this->label12->TabIndex = 37;
			this->label12->Text = L"Number of Clients";
			// 
			// TNumberOfClients
			// 
			this->TNumberOfClients->Location = System::Drawing::Point(85, 526);
			this->TNumberOfClients->Name = L"TNumberOfClients";
			this->TNumberOfClients->Size = System::Drawing::Size(50, 22);
			this->TNumberOfClients->TabIndex = 38;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->Cursor = System::Windows::Forms::Cursors::Default;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(52, 321);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 41);
			this->button1->TabIndex = 39;
			this->button1->Text = L"Connect";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// checkHostName
			// 
			this->checkHostName->AutoSize = true;
			this->checkHostName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkHostName->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkHostName->Location = System::Drawing::Point(6, 33);
			this->checkHostName->Name = L"checkHostName";
			this->checkHostName->Size = System::Drawing::Size(100, 21);
			this->checkHostName->TabIndex = 40;
			this->checkHostName->Text = L"Host Name";
			this->checkHostName->UseVisualStyleBackColor = true;
			// 
			// checkService
			// 
			this->checkService->AutoSize = true;
			this->checkService->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkService->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkService->Location = System::Drawing::Point(6, 61);
			this->checkService->Name = L"checkService";
			this->checkService->Size = System::Drawing::Size(77, 21);
			this->checkService->TabIndex = 41;
			this->checkService->Text = L"Service";
			this->checkService->UseVisualStyleBackColor = true;
			// 
			// checkIpAddress
			// 
			this->checkIpAddress->AutoSize = true;
			this->checkIpAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkIpAddress->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkIpAddress->Location = System::Drawing::Point(6, 89);
			this->checkIpAddress->Name = L"checkIpAddress";
			this->checkIpAddress->Size = System::Drawing::Size(97, 21);
			this->checkIpAddress->TabIndex = 42;
			this->checkIpAddress->Text = L"Ip Address";
			this->checkIpAddress->UseVisualStyleBackColor = true;
			// 
			// checkBiosVersion
			// 
			this->checkBiosVersion->AutoSize = true;
			this->checkBiosVersion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBiosVersion->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkBiosVersion->Location = System::Drawing::Point(6, 200);
			this->checkBiosVersion->Name = L"checkBiosVersion";
			this->checkBiosVersion->Size = System::Drawing::Size(114, 21);
			this->checkBiosVersion->TabIndex = 43;
			this->checkBiosVersion->Text = L"BIOS Version";
			this->checkBiosVersion->UseVisualStyleBackColor = true;
			// 
			// checkTotalPysicalMemory
			// 
			this->checkTotalPysicalMemory->AutoSize = true;
			this->checkTotalPysicalMemory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->checkTotalPysicalMemory->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkTotalPysicalMemory->Location = System::Drawing::Point(6, 173);
			this->checkTotalPysicalMemory->Name = L"checkTotalPysicalMemory";
			this->checkTotalPysicalMemory->Size = System::Drawing::Size(164, 21);
			this->checkTotalPysicalMemory->TabIndex = 44;
			this->checkTotalPysicalMemory->Text = L"Total Pysical Memory";
			this->checkTotalPysicalMemory->UseVisualStyleBackColor = true;
			// 
			// checkSystemManufacturer
			// 
			this->checkSystemManufacturer->AutoSize = true;
			this->checkSystemManufacturer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->checkSystemManufacturer->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkSystemManufacturer->Location = System::Drawing::Point(6, 146);
			this->checkSystemManufacturer->Name = L"checkSystemManufacturer";
			this->checkSystemManufacturer->Size = System::Drawing::Size(164, 21);
			this->checkSystemManufacturer->TabIndex = 45;
			this->checkSystemManufacturer->Text = L"System Manufacturer";
			this->checkSystemManufacturer->UseVisualStyleBackColor = true;
			// 
			// checkOsName
			// 
			this->checkOsName->AutoSize = true;
			this->checkOsName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkOsName->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkOsName->Location = System::Drawing::Point(6, 119);
			this->checkOsName->Name = L"checkOsName";
			this->checkOsName->Size = System::Drawing::Size(91, 21);
			this->checkOsName->TabIndex = 47;
			this->checkOsName->Text = L"OS Name";
			this->checkOsName->UseVisualStyleBackColor = true;
			// 
			// checkEthernet
			// 
			this->checkEthernet->AutoSize = true;
			this->checkEthernet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkEthernet->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->checkEthernet->Location = System::Drawing::Point(6, 229);
			this->checkEthernet->Name = L"checkEthernet";
			this->checkEthernet->Size = System::Drawing::Size(84, 21);
			this->checkEthernet->TabIndex = 48;
			this->checkEthernet->Text = L"Ethernet";
			this->checkEthernet->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkWifi);
			this->groupBox1->Controls->Add(this->checkSystemManufacturer);
			this->groupBox1->Controls->Add(this->checkOsName);
			this->groupBox1->Controls->Add(this->checkService);
			this->groupBox1->Controls->Add(this->checkHostName);
			this->groupBox1->Controls->Add(this->checkTotalPysicalMemory);
			this->groupBox1->Controls->Add(this->checkIpAddress);
			this->groupBox1->Controls->Add(this->checkBiosVersion);
			this->groupBox1->Controls->Add(this->checkEthernet);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::Red;
			this->groupBox1->Location = System::Drawing::Point(15, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(235, 293);
			this->groupBox1->TabIndex = 49;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Choose !";
			// 
			// checkWifi
			// 
			this->checkWifi->AutoSize = true;
			this->checkWifi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkWifi->ForeColor = System::Drawing::Color::Black;
			this->checkWifi->Location = System::Drawing::Point(6, 256);
			this->checkWifi->Name = L"checkWifi";
			this->checkWifi->Size = System::Drawing::Size(53, 21);
			this->checkWifi->TabIndex = 49;
			this->checkWifi->Text = L"Wifi";
			this->checkWifi->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::LightSteelBlue;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::Turquoise;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::HotTrack;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::ControlDark;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::WindowFrame;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(267, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::Bisque;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::MediumBlue;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::Bisque;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::MediumBlue;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1229, 874);
			this->dataGridView1->TabIndex = 91;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1508, 906);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->TNumberOfClients);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Server";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) 
	{
		
		SQLDatabase::SQLDatabase::createDB(dir);								// ClientsData.db adında database oluşur
		SQLDatabase::SQLDatabase::createTable(dir);								// Column değerleri oluşturulur
		SQLDatabase::SQLDatabase::deleteAllData(dir);							// Başlangıçta dosya temizlenir

		//*********************************************************************************************************************
		
		Serv.loadConfig();														// config.txt dosyasına ulaşır
		Serv.initializeWinsock();												// Winsock error değerine ulaşır

	//*************************************************************************************************************************	 

		String^ Serrorcode = System::Convert::ToString(Serv.errorMessage);		//  
		textBox1->Text = Serrorcode;											// hatanın kodunu yazar

	//*************************************************************************************************************************

		Serv.ErrorMessage();													//                             
		string errorCodeyeni = Serv.yazdirError();								//
		String^ strnew2 = gcnew String(errorCodeyeni.c_str());					// hatanın neden kaynaklandığını yazar
		textBox2->Text = strnew2;												//

	// ************************************************************************************************************************

		SOCKET listening = Serv.createdSocket();                                // soket oluşturuluyor

		string errorCreateSocket = Serv.errorMessageCreateSocket();				// Soket başarısızsa Hatanın neyden kaynaklandığı
		String^ SerrorCreateSocket = gcnew String(errorCreateSocket.c_str());	//
		textBox3->Text = SerrorCreateSocket;

		//*********************************************************************************************************************

		Serv.ConnectIpAndPort();											    // Config dosyasındaki ip'ye bağlan
		Serv.BindListening();
		Serv.listenSocket();
		System::Windows::Forms::Application::DoEvents();

		//*********************************************************************************************************************

		Serv.ListeningMaster();													// master oluşturuyor
		
		//*********************************************************************************************************************
		backgroundWorker1->RunWorkerAsync();
		//backgroundWorker2->RunWorkerAsync();
	}

private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
{
	int count = 0;
	Serv.oldValueNumberOfClient = 0;
	for (int i = 0; i < 100; i++)
	{
		Serv.sockArray[i] = 0;												// initialization
	}
	//********************************************************************************************************************
	DataTable^ dt = gcnew DataTable();
	dt->Columns->Add(gcnew DataColumn("HostName"));
	dt->Columns->Add(gcnew DataColumn("Service"));
	dt->Columns->Add(gcnew DataColumn("Ip Address"));
	dt->Columns->Add(gcnew DataColumn("Os Name"));							// Sutunları oluşturuyoruz
	dt->Columns->Add(gcnew DataColumn("System Manufacturer"));
	dt->Columns->Add(gcnew DataColumn("Total Pysical Memory"));
	dt->Columns->Add(gcnew DataColumn("Bios Version"));
	dt->Columns->Add(gcnew DataColumn("Ethernet"));
	dt->Columns->Add(gcnew DataColumn("Wifi"));

	//*********************************************************************************************************************

	while (1)
	{
		Serv.Sendip();
		
		String^ Shost = gcnew String(Serv.host);							// std::string System::string dönüşümü
		String^ Sservice = gcnew String(Serv.service);
		String^ Sip = gcnew String(Serv.ipAddress.c_str());
		String^ SOsName = gcnew String(Serv.OsName.c_str());
		String^ SsystemManufacturer = gcnew String(Serv.systemManufacturer.c_str());
		String^ SphysicalMemory = gcnew String(Serv.physicalMemory.c_str());
		String^ SbiosVersion = gcnew String(Serv.biosVersion.c_str());
		String^ Sethernet = gcnew String(Serv.ethernet.c_str());
		String^ Swifi = gcnew String(Serv.wifi.c_str());
		
		//*******************HostName, Service, ve Ip adreslerin yazdırılması *********************************************

		Serv.numberofclient = Serv.master.fd_count - 1;									// Serv.master.fd_count = sever ile client sayısının toplamı olduğundan 
																						// 1 çıkarılıyor  ve client sayısı bulunuyor.

		if ((Serv.oldValueNumberOfClient < Serv.numberofclient) && (count % 2 == 1))	// Client sayısının eski değeri küçük ise yeni bir client girişi
																						// olmuştur. Büyük ise client çıkış yapmıştır.
		{
			dt->Rows->Add(Shost, Sservice, Sip, SOsName, SsystemManufacturer,			// Data table'a yeni giriş olduğunda client bilgileri eklenir.
				SphysicalMemory, SbiosVersion, Sethernet, Swifi);
			
			/**********************************SQLİTE DATABASE ADDITION ********************************************************************************/
			
			SQLDatabase::SQLDatabase::insertData(dir, Serv.numberofclient, Serv.host,	// SQlite'a client giriş yaptığında yeni client
				Serv.service, Serv.ipAddress, Serv.OsName, Serv.systemManufacturer,		// bilgileri eklenir.
				 Serv.physicalMemory, Serv.biosVersion, Serv.ethernet, Serv.wifi);  
			SQLDatabase::SQLDatabase::selectData(dir);									// command window'da bilgileri ekranda gösterir
			
			/*******************************************************************************************************************************************/
			Serv.oldValueNumberOfClient = Serv.numberofclient;					// client eski değerini yeniliyoruz.
		}

		else if (Serv.oldValueNumberOfClient > Serv.numberofclient)				// client çıkışı olduğunda
		{
			for (int i = 0; i <= Serv.numberofclient + 1; i++)					
			{
				if (Serv.sockArray[i] == Serv.sock)								// Bütün clientları tara ve çıkış yapılan socket değeri hangi clienta aitse ...
				{																
					dt->Rows->RemoveAt(i - 1);									// çıkış yapılan client'ı kaldır	
					
					SQLDatabase::SQLDatabase::deleteData(dir, i);				// ClientsData.db' den kaldır
					//SQLDatabase::SQLDatabase::selectData(dir);
					
					for (i; i < MAXCLIENT; i++)									
					{															
						Serv.sockArray[i] = Serv.sockArray[i + 1];				// Çıkış yapılan clienttan sonrasındaki değerleri bir kaydır
						SQLDatabase::SQLDatabase::updateData(dir,i,i+1);		// ClientsData.db' de clienttan sonraki değerleri bir kaydır
					}
				}
			}

			count--;															// Her çıkış yapıldığında 1 eksilt
			Serv.oldValueNumberOfClient = Serv.numberofclient;					// Eski client sayısı değerini yenile
		}
		dataGridView1->DataSource = dt;

		// ********************************************* Check Box Configration *****************************************************
		if (checkHostName->Checked == false)
		{
			dataGridView1->Columns["HostName"]->Visible = false;
		}
		else
			dataGridView1->Columns["HostName"]->Visible = true;
		if (checkService->Checked == false)
		{
			dataGridView1->Columns["Service"]->Visible = false;
		}
		else
			dataGridView1->Columns["Service"]->Visible = true;
		if (checkIpAddress->Checked == false)
		{
			dataGridView1->Columns["Ip Address"]->Visible = false;
		}
		else
			dataGridView1->Columns["Ip Address"]->Visible = true;
		if (checkOsName->Checked == false)
		{
			dataGridView1->Columns["Os Name"]->Visible = false;
		}
		else
			dataGridView1->Columns["Os Name"]->Visible = true;
		if (checkSystemManufacturer->Checked == false)
		{
			dataGridView1->Columns["System Manufacturer"]->Visible = false;
		}
		else
			dataGridView1->Columns["System Manufacturer"]->Visible = true;
		if (checkTotalPysicalMemory->Checked == false)
		{
			dataGridView1->Columns["Total Pysical Memory"]->Visible = false;
		}
		else
			dataGridView1->Columns["Total Pysical Memory"]->Visible = true;
		if (checkBiosVersion->Checked == false)
		{
			dataGridView1->Columns["Bios Version"]->Visible = false;
		}
		else
			dataGridView1->Columns["Bios Version"]->Visible = true;
		if (checkEthernet->Checked == false)
		{
			dataGridView1->Columns["Ethernet"]->Visible = false;
		}
		else
			dataGridView1->Columns["Ethernet"]->Visible = true;
		if (checkEthernet->Checked == false)
		{
			dataGridView1->Columns["Wifi"]->Visible = false;
		}
		else
			dataGridView1->Columns["Wifi"]->Visible = true;
		//****************************************************************************************************************
		dataGridView1->Refresh();
		dataGridView1->Update();
		//****************************************************************************************************************
		String^ ScCount = System::Convert::ToString(Serv.master.fd_count - 1);			// Bağlanan client sayısı yazdırılır
		TNumberOfClients->Text = ScCount;
		System::Windows::Forms::Application::DoEvents();

		count++;
	}
}
private: System::Void backgroundWorker2_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

}
};
}
