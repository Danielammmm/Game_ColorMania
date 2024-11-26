#pragma once
#include "Pila.h"
#include "Lista.h"
#include "Cola.h"
#include "Ordenamiento.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>

namespace ColorMania {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		List<Pila^>^ pilas;
		int cantidadPilas;
		int capacidadPila;
		List<String^>^ elementos;
		StringBuilder^ registroMovimientos = gcnew StringBuilder();


		int cantidad_movimientos = 0;
		int tiempo_limite = 0; // en segundos
		DateTime horaFinal;

		List<Cola^>^ colas;

		int totalMovimientos = 0;
		bool juegoTerminado = false;

		private: System::Windows::Forms::Label^ lbl_c;

	private: System::Windows::Forms::Label^ lbl_P1;
	private: System::Windows::Forms::Label^ lbl_P2;

	private: System::Windows::Forms::Label^ lbl_modojuego;
	private: System::Windows::Forms::TextBox^ txt_origen;
	private: System::Windows::Forms::TextBox^ txt_destino;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lbl_origen;
	private: System::Windows::Forms::Label^ lbl_destino;
	private: System::Windows::Forms::ComboBox^ comboBox_modo;

	private: System::Windows::Forms::Button^ btn_cambiar;
	private: System::Windows::Forms::Button^ btn_comenzar;

	private: System::Windows::Forms::RadioButton^ rbtn_pila;
	private: System::Windows::Forms::RadioButton^ rbtn_cola;
	private: System::Windows::Forms::Label^ lbl_movimientos;
	private: System::Windows::Forms::Label^ lbl_tiempo_restante;
	private: System::Windows::Forms::Button^ btn_descargarDatos;
	private: System::Windows::Forms::Button^ btn_terminar;
	private: System::Windows::Forms::Button^ btn_solucion;





	private: System::Windows::Forms::DataGridView^ dataGridView1;

		  

	public:
		MyForm()
		{
			InitializeComponent();
			pilas = gcnew List<Pila^>();
			cantidadPilas = 0;
			capacidadPila = 0;
			elementos = gcnew List<String^>();
			colas = gcnew List<Cola^>();



		}

	protected:
		
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ lbl;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txt_CantidadPilas;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ txtCapacidadPilas;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ btn_buscararchivo;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::ComponentModel::IContainer^ components;



	protected:

	private:
		


#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lbl = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txt_CantidadPilas = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtCapacidadPilas = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->btn_buscararchivo = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->lbl_c = (gcnew System::Windows::Forms::Label());
			this->lbl_P1 = (gcnew System::Windows::Forms::Label());
			this->lbl_P2 = (gcnew System::Windows::Forms::Label());
			this->lbl_modojuego = (gcnew System::Windows::Forms::Label());
			this->txt_origen = (gcnew System::Windows::Forms::TextBox());
			this->txt_destino = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_origen = (gcnew System::Windows::Forms::Label());
			this->lbl_destino = (gcnew System::Windows::Forms::Label());
			this->comboBox_modo = (gcnew System::Windows::Forms::ComboBox());
			this->btn_cambiar = (gcnew System::Windows::Forms::Button());
			this->btn_comenzar = (gcnew System::Windows::Forms::Button());
			this->rbtn_pila = (gcnew System::Windows::Forms::RadioButton());
			this->rbtn_cola = (gcnew System::Windows::Forms::RadioButton());
			this->lbl_movimientos = (gcnew System::Windows::Forms::Label());
			this->lbl_tiempo_restante = (gcnew System::Windows::Forms::Label());
			this->btn_descargarDatos = (gcnew System::Windows::Forms::Button());
			this->btn_terminar = (gcnew System::Windows::Forms::Button());
			this->btn_solucion = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Orange;
			this->label1->Location = System::Drawing::Point(146, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 60);
			this->label1->TabIndex = 0;
			this->label1->Text = L"C";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label2->Location = System::Drawing::Point(194, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 60);
			this->label2->TabIndex = 1;
			this->label2->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::MediumSpringGreen;
			this->label3->Location = System::Drawing::Point(245, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 60);
			this->label3->TabIndex = 2;
			this->label3->Text = L"L";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Yellow;
			this->label4->Location = System::Drawing::Point(287, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 60);
			this->label4->TabIndex = 3;
			this->label4->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::DarkOrchid;
			this->label5->Location = System::Drawing::Point(334, 25);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(64, 60);
			this->label5->TabIndex = 4;
			this->label5->Text = L"R";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(420, 25);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(70, 60);
			this->label6->TabIndex = 5;
			this->label6->Text = L"M";
			// 
			// lbl
			// 
			this->lbl->AutoSize = true;
			this->lbl->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl->ForeColor = System::Drawing::Color::Cyan;
			this->lbl->Location = System::Drawing::Point(474, 25);
			this->lbl->Name = L"lbl";
			this->lbl->Size = System::Drawing::Size(68, 60);
			this->lbl->TabIndex = 6;
			this->lbl->Text = L"A";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Magenta;
			this->label8->Location = System::Drawing::Point(530, 25);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 60);
			this->label8->TabIndex = 7;
			this->label8->Text = L"N";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Lime;
			this->label9->Location = System::Drawing::Point(577, 25);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(46, 60);
			this->label9->TabIndex = 8;
			this->label9->Text = L"I";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::BlueViolet;
			this->label10->Location = System::Drawing::Point(602, 25);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(68, 60);
			this->label10->TabIndex = 9;
			this->label10->Text = L"A";
			// 
			// txt_CantidadPilas
			// 
			this->txt_CantidadPilas->BackColor = System::Drawing::SystemColors::MenuText;
			this->txt_CantidadPilas->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->txt_CantidadPilas->Location = System::Drawing::Point(119, 156);
			this->txt_CantidadPilas->Name = L"txt_CantidadPilas";
			this->txt_CantidadPilas->Size = System::Drawing::Size(72, 22);
			this->txt_CantidadPilas->TabIndex = 10;
			this->txt_CantidadPilas->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txt_CantidadPilas->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_CantidadPilas_TextChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(37, 124);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(183, 18);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Ingrese datos de pilas: ";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(206, 169);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"¡Listo!";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// txtCapacidadPilas
			// 
			this->txtCapacidadPilas->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtCapacidadPilas->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->txtCapacidadPilas->Location = System::Drawing::Point(117, 189);
			this->txtCapacidadPilas->Name = L"txtCapacidadPilas";
			this->txtCapacidadPilas->Size = System::Drawing::Size(74, 22);
			this->txtCapacidadPilas->TabIndex = 14;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(37, 159);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(61, 16);
			this->label13->TabIndex = 15;
			this->label13->Text = L"Cantidad";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(37, 192);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(74, 16);
			this->label14->TabIndex = 16;
			this->label14->Text = L"Capacidad";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(293, 124);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(146, 18);
			this->label12->TabIndex = 13;
			this->label12->Text = L"Ingrese del mapa: ";
			// 
			// btn_buscararchivo
			// 
			this->btn_buscararchivo->BackColor = System::Drawing::Color::Black;
			this->btn_buscararchivo->ForeColor = System::Drawing::Color::White;
			this->btn_buscararchivo->Location = System::Drawing::Point(315, 156);
			this->btn_buscararchivo->Name = L"btn_buscararchivo";
			this->btn_buscararchivo->Size = System::Drawing::Size(100, 49);
			this->btn_buscararchivo->TabIndex = 17;
			this->btn_buscararchivo->Text = L"Buscar Archivo...";
			this->btn_buscararchivo->UseVisualStyleBackColor = false;
			this->btn_buscararchivo->Click += gcnew System::EventHandler(this, &MyForm::btn_buscararchivo_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(34, 217);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(775, 232);
			this->dataGridView1->TabIndex = 18;
			// 
			// lbl_c
			// 
			this->lbl_c->AutoSize = true;
			this->lbl_c->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_c->Location = System::Drawing::Point(830, 156);
			this->lbl_c->Name = L"lbl_c";
			this->lbl_c->Size = System::Drawing::Size(152, 18);
			this->lbl_c->TabIndex = 19;
			this->lbl_c->Text = L"Comenzar a jugar: ";
			this->lbl_c->Visible = false;
			// 
			// lbl_P1
			// 
			this->lbl_P1->AutoSize = true;
			this->lbl_P1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_P1->Location = System::Drawing::Point(830, 275);
			this->lbl_P1->Name = L"lbl_P1";
			this->lbl_P1->Size = System::Drawing::Size(19, 18);
			this->lbl_P1->TabIndex = 20;
			this->lbl_P1->Text = L"P";
			this->lbl_P1->Visible = false;
			// 
			// lbl_P2
			// 
			this->lbl_P2->AutoSize = true;
			this->lbl_P2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_P2->Location = System::Drawing::Point(923, 276);
			this->lbl_P2->Name = L"lbl_P2";
			this->lbl_P2->Size = System::Drawing::Size(19, 18);
			this->lbl_P2->TabIndex = 21;
			this->lbl_P2->Text = L"P";
			this->lbl_P2->Visible = false;
			// 
			// lbl_modojuego
			// 
			this->lbl_modojuego->AutoSize = true;
			this->lbl_modojuego->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_modojuego->Location = System::Drawing::Point(480, 137);
			this->lbl_modojuego->Name = L"lbl_modojuego";
			this->lbl_modojuego->Size = System::Drawing::Size(177, 22);
			this->lbl_modojuego->TabIndex = 22;
			this->lbl_modojuego->Text = L"Ingrese modo de juego: ";
			this->lbl_modojuego->UseCompatibleTextRendering = true;
			this->lbl_modojuego->Visible = false;
			// 
			// txt_origen
			// 
			this->txt_origen->Location = System::Drawing::Point(855, 271);
			this->txt_origen->Name = L"txt_origen";
			this->txt_origen->Size = System::Drawing::Size(37, 22);
			this->txt_origen->TabIndex = 23;
			this->txt_origen->Visible = false;
			this->txt_origen->WordWrap = false;
			// 
			// txt_destino
			// 
			this->txt_destino->Location = System::Drawing::Point(948, 271);
			this->txt_destino->Name = L"txt_destino";
			this->txt_destino->Size = System::Drawing::Size(37, 22);
			this->txt_destino->TabIndex = 24;
			this->txt_destino->Visible = false;
			// 
			// lbl_origen
			// 
			this->lbl_origen->AutoSize = true;
			this->lbl_origen->Location = System::Drawing::Point(848, 296);
			this->lbl_origen->Name = L"lbl_origen";
			this->lbl_origen->Size = System::Drawing::Size(45, 16);
			this->lbl_origen->TabIndex = 25;
			this->lbl_origen->Text = L"origen";
			this->lbl_origen->Visible = false;
			// 
			// lbl_destino
			// 
			this->lbl_destino->AutoSize = true;
			this->lbl_destino->Location = System::Drawing::Point(945, 296);
			this->lbl_destino->Name = L"lbl_destino";
			this->lbl_destino->Size = System::Drawing::Size(51, 16);
			this->lbl_destino->TabIndex = 26;
			this->lbl_destino->Text = L"destino";
			this->lbl_destino->Visible = false;
			// 
			// comboBox_modo
			// 
			this->comboBox_modo->BackColor = System::Drawing::Color::Black;
			this->comboBox_modo->ForeColor = System::Drawing::SystemColors::Window;
			this->comboBox_modo->FormattingEnabled = true;
			this->comboBox_modo->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Fácil", L"Medio", L"Difícil" });
			this->comboBox_modo->Location = System::Drawing::Point(484, 169);
			this->comboBox_modo->Name = L"comboBox_modo";
			this->comboBox_modo->Size = System::Drawing::Size(186, 24);
			this->comboBox_modo->TabIndex = 27;
			this->comboBox_modo->Visible = false;
			// 
			// btn_cambiar
			// 
			this->btn_cambiar->BackColor = System::Drawing::Color::Black;
			this->btn_cambiar->ForeColor = System::Drawing::Color::White;
			this->btn_cambiar->Location = System::Drawing::Point(866, 325);
			this->btn_cambiar->Name = L"btn_cambiar";
			this->btn_cambiar->Size = System::Drawing::Size(102, 51);
			this->btn_cambiar->TabIndex = 28;
			this->btn_cambiar->Text = L"Realizar Cambio";
			this->btn_cambiar->UseVisualStyleBackColor = false;
			this->btn_cambiar->Visible = false;
			this->btn_cambiar->Click += gcnew System::EventHandler(this, &MyForm::btn_cambiar_Click);
			// 
			// btn_comenzar
			// 
			this->btn_comenzar->BackColor = System::Drawing::Color::Black;
			this->btn_comenzar->ForeColor = System::Drawing::Color::White;
			this->btn_comenzar->Location = System::Drawing::Point(701, 143);
			this->btn_comenzar->Name = L"btn_comenzar";
			this->btn_comenzar->Size = System::Drawing::Size(86, 49);
			this->btn_comenzar->TabIndex = 29;
			this->btn_comenzar->Text = L"Iniciar Juego";
			this->btn_comenzar->UseVisualStyleBackColor = false;
			this->btn_comenzar->Visible = false;
			this->btn_comenzar->Click += gcnew System::EventHandler(this, &MyForm::btn_comenzar_Click);
			// 
			// rbtn_pila
			// 
			this->rbtn_pila->AutoSize = true;
			this->rbtn_pila->Checked = true;
			this->rbtn_pila->Location = System::Drawing::Point(835, 396);
			this->rbtn_pila->Name = L"rbtn_pila";
			this->rbtn_pila->Size = System::Drawing::Size(58, 20);
			this->rbtn_pila->TabIndex = 30;
			this->rbtn_pila->TabStop = true;
			this->rbtn_pila->Text = L"Pilas";
			this->rbtn_pila->UseVisualStyleBackColor = true;
			this->rbtn_pila->Visible = false;
			this->rbtn_pila->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbtn_pila_CheckedChanged);
			// 
			// rbtn_cola
			// 
			this->rbtn_cola->AutoSize = true;
			this->rbtn_cola->Location = System::Drawing::Point(933, 396);
			this->rbtn_cola->Name = L"rbtn_cola";
			this->rbtn_cola->Size = System::Drawing::Size(63, 20);
			this->rbtn_cola->TabIndex = 31;
			this->rbtn_cola->Text = L"Colas";
			this->rbtn_cola->UseVisualStyleBackColor = true;
			this->rbtn_cola->Visible = false;
			this->rbtn_cola->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbtn_cola_CheckedChanged);
			// 
			// lbl_movimientos
			// 
			this->lbl_movimientos->AutoSize = true;
			this->lbl_movimientos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_movimientos->Location = System::Drawing::Point(833, 228);
			this->lbl_movimientos->Name = L"lbl_movimientos";
			this->lbl_movimientos->Size = System::Drawing::Size(146, 20);
			this->lbl_movimientos->TabIndex = 32;
			this->lbl_movimientos->Text = L"Movimientos restantes: ";
			this->lbl_movimientos->UseCompatibleTextRendering = true;
			this->lbl_movimientos->Visible = false;
			this->lbl_movimientos->Click += gcnew System::EventHandler(this, &MyForm::lbl_movimietnos_Click);
			// 
			// lbl_tiempo_restante
			// 
			this->lbl_tiempo_restante->AutoSize = true;
			this->lbl_tiempo_restante->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbl_tiempo_restante->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_tiempo_restante->ForeColor = System::Drawing::SystemColors::Control;
			this->lbl_tiempo_restante->Location = System::Drawing::Point(833, 192);
			this->lbl_tiempo_restante->Name = L"lbl_tiempo_restante";
			this->lbl_tiempo_restante->Size = System::Drawing::Size(0, 19);
			this->lbl_tiempo_restante->TabIndex = 33;
			this->lbl_tiempo_restante->UseCompatibleTextRendering = true;
			this->lbl_tiempo_restante->Visible = false;
			// 
			// btn_descargarDatos
			// 
			this->btn_descargarDatos->BackColor = System::Drawing::Color::Black;
			this->btn_descargarDatos->ForeColor = System::Drawing::Color::White;
			this->btn_descargarDatos->Location = System::Drawing::Point(156, 455);
			this->btn_descargarDatos->Name = L"btn_descargarDatos";
			this->btn_descargarDatos->Size = System::Drawing::Size(195, 27);
			this->btn_descargarDatos->TabIndex = 34;
			this->btn_descargarDatos->Text = L"Descargar Movimientos";
			this->btn_descargarDatos->UseVisualStyleBackColor = false;
			this->btn_descargarDatos->Visible = false;
			this->btn_descargarDatos->Click += gcnew System::EventHandler(this, &MyForm::btn_descargarDatos_Click);
			// 
			// btn_terminar
			// 
			this->btn_terminar->BackColor = System::Drawing::Color::Black;
			this->btn_terminar->ForeColor = System::Drawing::Color::White;
			this->btn_terminar->Location = System::Drawing::Point(866, 422);
			this->btn_terminar->Name = L"btn_terminar";
			this->btn_terminar->Size = System::Drawing::Size(102, 51);
			this->btn_terminar->TabIndex = 35;
			this->btn_terminar->Text = L"Terminar...";
			this->btn_terminar->UseVisualStyleBackColor = false;
			this->btn_terminar->Visible = false;
			this->btn_terminar->Click += gcnew System::EventHandler(this, &MyForm::btn_terminar_Click);
			// 
			// btn_solucion
			// 
			this->btn_solucion->BackColor = System::Drawing::Color::Black;
			this->btn_solucion->ForeColor = System::Drawing::Color::White;
			this->btn_solucion->Location = System::Drawing::Point(444, 455);
			this->btn_solucion->Name = L"btn_solucion";
			this->btn_solucion->Size = System::Drawing::Size(195, 27);
			this->btn_solucion->TabIndex = 36;
			this->btn_solucion->Text = L"Obtener Solucion";
			this->btn_solucion->UseVisualStyleBackColor = false;
			this->btn_solucion->Visible = false;
			this->btn_solucion->Click += gcnew System::EventHandler(this, &MyForm::btn_solucion_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowText;
			this->ClientSize = System::Drawing::Size(1059, 511);
			this->Controls->Add(this->btn_solucion);
			this->Controls->Add(this->btn_terminar);
			this->Controls->Add(this->btn_descargarDatos);
			this->Controls->Add(this->lbl_tiempo_restante);
			this->Controls->Add(this->lbl_movimientos);
			this->Controls->Add(this->rbtn_cola);
			this->Controls->Add(this->rbtn_pila);
			this->Controls->Add(this->btn_comenzar);
			this->Controls->Add(this->btn_cambiar);
			this->Controls->Add(this->comboBox_modo);
			this->Controls->Add(this->lbl_destino);
			this->Controls->Add(this->lbl_origen);
			this->Controls->Add(this->txt_destino);
			this->Controls->Add(this->txt_origen);
			this->Controls->Add(this->lbl_modojuego);
			this->Controls->Add(this->lbl_P2);
			this->Controls->Add(this->lbl_P1);
			this->Controls->Add(this->lbl_c);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->btn_buscararchivo);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->txtCapacidadPilas);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->txt_CantidadPilas);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->lbl);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}



#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void txt_CantidadPilas_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btn_buscararchivo_Click(System::Object^ sender, System::EventArgs^ e) {
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		try {
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);
			String^ line = sr->ReadLine();
			sr->Close();

			// Separar los colores por comas
			array<String^>^ colores = line->Split(',');

			// Leer la cantidad de pilas y la capacidad de cada pila
			cantidadPilas = Convert::ToInt32(txt_CantidadPilas->Text);
			capacidadPila = Convert::ToInt32(txtCapacidadPilas->Text);

			// Limpiar el DataGridView
			dataGridView1->Rows->Clear();
			dataGridView1->Columns->Clear();

			// Crear columnas para el DataGridView (una columna por pila)
			for (int i = 0; i < cantidadPilas; i++) {
				dataGridView1->Columns->Add("Pila" + i, "Pila " + (i + 1));
			}

			// Llenar el DataGridView con los colores de forma vertical
			int index = 0;
			int fila = 0;
			int columna = 0;
			while (index < colores->Length) {
				if (colores[index] != "X") {
					dataGridView1->Rows->Add();
					dataGridView1->Rows[fila]->Cells[columna]->Value = colores[index];
					AsignarColorACelda(dataGridView1->Rows[fila]->Cells[columna]);
					fila++;
				}
				else {
					fila = 0;
					columna++;
				}
				index++;
			}

			lbl_modojuego->Visible = true;
			comboBox_modo->Visible = true;
			btn_comenzar->Visible = true;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al cargar el archivo: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}



private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Obtener la cantidad y capacidad de las pilas desde los TextBox
	if (txt_CantidadPilas->Text == "" || txtCapacidadPilas->Text == "") {
		MessageBox::Show("Debes ingresar la cantidad y capacidad de pilas primero.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Obtener la cantidad de pilas y capacidad de cada pila
	cantidadPilas = Convert::ToInt32(txt_CantidadPilas->Text);
	capacidadPila = Convert::ToInt32(txtCapacidadPilas->Text);

	// Limpiar el DataGridView
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	// Crear columnas para el DataGridView
	for (int i = 0; i < cantidadPilas; i++) {
		dataGridView1->Columns->Add("Pila" + i, "Pila " + i);
	}

	// Crear las pilas
	pilas->Clear();
	for (int i = 0; i < cantidadPilas; i++) {
		Pila^ pila = gcnew Pila(capacidadPila);
		pilas->Add(pila);
	}

	// Mostrar las pilas en el DataGridView
	for (int i = 0; i < capacidadPila; i++) {
		dataGridView1->Rows->Add();
	}
}

	   void AsignarColorACelda(DataGridViewCell^ celda) {
		   Object^ valorCelda = celda->Value;
		   if (valorCelda != nullptr) {
			   String^ color = valorCelda->ToString();
			   if (color == "A") {
				   celda->Style->BackColor = System::Drawing::Color::Yellow;
			   }
			   else if (color == "R") {
				   celda->Style->BackColor = System::Drawing::Color::Red;
			   }
			   else if (color == "V") {
				   celda->Style->BackColor = System::Drawing::Color::Green;
			   }
			   else if (color == "M") {
				   celda->Style->BackColor = System::Drawing::Color::Purple;
			   }
			   else if (color == "N") {
				   celda->Style->BackColor = System::Drawing::Color::Orange;
			   }
			   else if (color == "C") {
				   celda->Style->BackColor = System::Drawing::Color::Cyan;
			   }
			   else if (color == "F") {
				   celda->Style->BackColor = System::Drawing::Color::Pink;
			   }
		   }
	   }



private: System::Void rbtn_pila_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// Inicializa una pila y una cola
	Pila^ pila = gcnew Pila(cantidadPilas * capacidadPila);
	Cola^ cola = gcnew Cola();

	// Asegúrate de tener acceso a tus datos del DataGridView
	// Ya sea que los hayas almacenado previamente en una estructura de datos o los obtengas directamente de las celdas del DataGridView

	if (rbtn_pila->Checked) {
		// Mueve los datos a la pila
		for (int columna = 0; columna < cantidadPilas; columna++) {
			for (int fila = dataGridView1->RowCount - 1; fila >= 0; fila--) {
				if (dataGridView1->Rows[fila]->Cells[columna]->Value != nullptr) {
					pila->Push(dataGridView1->Rows[fila]->Cells[columna]->Value->ToString());
				}
			}
		}
	}
	else if (rbtn_cola->Checked) {
		// Mueve los datos a la cola
		for (int fila = dataGridView1->RowCount - 1; fila >= 0; fila--) {
			for (int columna = 0; columna < cantidadPilas; columna++) {
				if (dataGridView1->Rows[fila]->Cells[columna]->Value != nullptr) {
					cola->Encolar(dataGridView1->Rows[fila]->Cells[columna]->Value->ToString());
				}
			}
		}
	}
	if (rbtn_pila->Checked) {
		// Cambiaste a pila
		MessageBox::Show("Cambiaste a Pila con éxito.", "Cambio Exitoso", MessageBoxButtons::OK, MessageBoxIcon::Information);

		lbl_P1->Text = "P";
		lbl_P2->Text = "P";
	}
}



private: System::Void rbtn_cola_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// Inicializa una pila y una cola
	Pila^ pila = gcnew Pila(cantidadPilas * capacidadPila);
	Cola^ cola = gcnew Cola();

	// Asegúrate de tener acceso a tus datos del DataGridView
	// Ya sea que los hayas almacenado previamente en una estructura de datos o los obtengas directamente de las celdas del DataGridView

	if (rbtn_pila->Checked) {
		// Mueve los datos a la pila
		for (int columna = 0; columna < cantidadPilas; columna++) {
			for (int fila = dataGridView1->RowCount - 1; fila >= 0; fila--) {
				if (dataGridView1->Rows[fila]->Cells[columna]->Value != nullptr) {
					pila->Push(dataGridView1->Rows[fila]->Cells[columna]->Value->ToString());
				}
			}
		}
	}
	else if (rbtn_cola->Checked) {
		// Mueve los datos a la cola
		for (int fila = dataGridView1->RowCount - 1; fila >= 0; fila--) {
			for (int columna = 0; columna < cantidadPilas; columna++) {
				if (dataGridView1->Rows[fila]->Cells[columna]->Value != nullptr) {
					cola->Encolar(dataGridView1->Rows[fila]->Cells[columna]->Value->ToString());
				}
			}
		}
	}
	 if (rbtn_cola->Checked) {
        // Cambiaste a pila
        MessageBox::Show("Cambiaste a Cola con éxito.", "Cambio Exitoso", MessageBoxButtons::OK, MessageBoxIcon::Information);
		lbl_P1->Text = "C";
		lbl_P2->Text = "C";
        
    }
}


private: System::Void lbl_movimietnos_Click(System::Object^ sender, System::EventArgs^ e) {
}


	   System::Void btn_comenzar_Click(System::Object^ sender, System::EventArgs^ e) {
		   // Obtén el modo seleccionado en el ComboBox
		   String^ modo = comboBox_modo->Text;

		   // Configura la cantidad de movimientos y el tiempo según el modo
		   if (modo == "Fácil") {
			   cantidad_movimientos = 100000000000000000; // Sin restricción de movimientos
			   tiempo_limite = 0; // Sin límite de tiempo
		   }
		   else if (modo == "Medio") {
			   cantidad_movimientos = 50; // Límite de 50 movimientos
			   tiempo_limite = 600; // 10 minutos en segundos
		   }
		   else if (modo == "Difícil") {
			   cantidad_movimientos = 25; // Límite de 25 movimientos
			   tiempo_limite = 300; // 5 minutos en segundos
		   }

		   // Restablece la hora final si el modo no es "Fácil"
		   if (modo != "Fácil") {
			   horaFinal = DateTime::Now.AddSeconds(tiempo_limite);
		   }

		   // Restablece el temporizador si el modo no es "Fácil"
		   if (modo != "Fácil") {
			   timer1->Interval = 1000; // Intervalo de 1 segundo
			   timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   ActualizarLabelTiempo();
			   timer1->Start();
		   }

		   // Restablece la etiqueta de movimientos restantes si el modo no es "Fácil"
		   if (modo != "Fácil") {
			   ActualizarLabelMovimientos();
		   }

		   // Hacer visibles los elementos
		   lbl_movimientos->Visible = true;
		   lbl_c->Visible = true;
		   lbl_P1->Visible = true;
		   txt_origen->Visible = true;
		   lbl_P2->Visible = true;
		   txt_destino->Visible = true;
		   lbl_origen->Visible = true;
		   lbl_destino->Visible = true;
		   btn_cambiar->Visible = true;
		   rbtn_pila->Visible = true;
		   rbtn_cola->Visible = true;
		   btn_descargarDatos->Visible = true;
		   btn_solucion->Visible = true;
		   // Actualizar la etiqueta del tiempo restante
		   lbl_tiempo_restante->Visible = true;
		   btn_terminar->Visible = true;
	   }

		private: System::Void btn_cambiar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Obtén la capacidad del contenedor desde el TextBox
	int capacidad = System::Convert::ToInt32(txtCapacidadPilas->Text);
	// Obtén el índice de la columna de origen y destino desde los TextBox
	int origen = System::Convert::ToInt32(txt_origen->Text) - 1;
	int destino = System::Convert::ToInt32(txt_destino->Text) - 1;
	String^ movimiento = "";

	// Verificar si es una pila o una cola
	if (rbtn_pila->Checked) {
		// Obtén el nodo que se elimina de la pila origen
		Object^ nodoEliminado = dataGridView1->Rows[0]->Cells[origen]->Value;

		// Verificar si la pila destino está llena
		if (dataGridView1->Rows[capacidad - 1]->Cells[destino]->Value != nullptr) {
			// La pila destino está llena, mostrar un mensaje y salir
			MessageBox::Show("La pila destino está llena. No se pueden agregar más elementos.", "Pila Destino Llena", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Realiza el desplazamiento de los nodos en la pila origen hacia abajo
		for (int fila = 0; fila < capacidad - 1; fila++) {
			Object^ nodoSiguiente = dataGridView1->Rows[fila + 1]->Cells[origen]->Value;
			dataGridView1->Rows[fila]->Cells[origen]->Value = nodoSiguiente;
			AsignarColorACelda(dataGridView1->Rows[fila]->Cells[origen]); // Cambiar el color
		}

		// Borra el nodo en la parte inferior de la pila origen
		dataGridView1->Rows[capacidad - 1]->Cells[origen]->Value = nullptr;
		dataGridView1->Rows[capacidad - 1]->Cells[origen]->Style->BackColor = System::Drawing::Color::White;

		// Realiza el desplazamiento de los nodos en la pila destino hacia abajo
		for (int fila = capacidad - 1; fila > 0; fila--) {
			Object^ nodoAnterior = dataGridView1->Rows[fila - 1]->Cells[destino]->Value;
			dataGridView1->Rows[fila]->Cells[destino]->Value = nodoAnterior;
			AsignarColorACelda(dataGridView1->Rows[fila]->Cells[destino]); // Cambiar el color
		}

		// Agrega el nodo eliminado a la parte superior de la pila destino
		dataGridView1->Rows[0]->Cells[destino]->Value = nodoEliminado;
		AsignarColorACelda(dataGridView1->Rows[0]->Cells[destino]); // Cambiar el color

		// Decrementar los movimientos restantes
		String^ modo = comboBox_modo->Text;
		if (modo != "Fácil") {
			cantidad_movimientos--;
			ActualizarLabelMovimientos();
		}

		// Verificar si se agotaron los movimientos
		if (cantidad_movimientos == 0) {
			// Detener el temporizador
			timer1->Stop();
			// Ocultar elementos y mostrar cuadro de diálogo
			lbl_movimientos->Visible = false;
			lbl_c->Visible = false;
			lbl_P1->Visible = false;
			txt_origen->Visible = false;
			lbl_P2->Visible = false;
			txt_destino->Visible = false;
			lbl_origen->Visible = false;
			lbl_destino->Visible = false;
			btn_cambiar->Visible = false;
			rbtn_pila->Visible = false;
			rbtn_cola->Visible = false;
			lbl_tiempo_restante->Visible = false;

			MessageBox::Show("¡Se agotaron los movimientos! El juego ha terminado.", "Fin del Juego");
		}

		// Establecer celdas vacías en blanco
		for (int fila = 0; fila < capacidad; fila++) {
			if (dataGridView1->Rows[fila]->Cells[origen]->Value == nullptr) {
				dataGridView1->Rows[fila]->Cells[origen]->Style->BackColor = System::Drawing::Color::White;
			}
			if (dataGridView1->Rows[fila]->Cells[destino]->Value == nullptr) {
				dataGridView1->Rows[fila]->Cells[destino]->Style->BackColor = System::Drawing::Color::White;
			}
		}

		movimiento = String::Format("P{0},P{1}", origen + 1, destino + 1);
	}
	else if (rbtn_cola->Checked) {
		// Obtén el nodo que se elimina de la cola origen
		Object^ nodoEliminado = dataGridView1->Rows[0]->Cells[origen]->Value;

		// Verificar si la cola destino está llena
		if (dataGridView1->Rows[capacidad - 1]->Cells[destino]->Value != nullptr) {
			// La cola destino está llena, mostrar un mensaje y salir
			MessageBox::Show("La cola destino está llena. No se pueden agregar más elementos.", "Cola Destino Llena", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Realiza el desplazamiento de los nodos en la cola origen hacia arriba
		for (int fila = 0; fila < capacidad - 1; fila++) {
			Object^ nodoSiguiente = dataGridView1->Rows[fila + 1]->Cells[origen]->Value;
			dataGridView1->Rows[fila]->Cells[origen]->Value = nodoSiguiente;
			AsignarColorACelda(dataGridView1->Rows[fila]->Cells[origen]); // Cambiar el color
		}

		// Borra el nodo en la parte inferior de la cola origen
		dataGridView1->Rows[capacidad - 1]->Cells[origen]->Value = nullptr;
		dataGridView1->Rows[capacidad - 1]->Cells[origen]->Style->BackColor = System::Drawing::Color::White;

		// Realiza el desplazamiento de los nodos en la cola destino hacia abajo
		for (int fila = capacidad - 1; fila > 0; fila--) {
			Object^ nodoAnterior = dataGridView1->Rows[fila - 1]->Cells[destino]->Value;
			dataGridView1->Rows[fila]->Cells[destino]->Value = nodoAnterior;
			AsignarColorACelda(dataGridView1->Rows[fila]->Cells[destino]); // Cambiar el color
		}

		// Agrega el nodo eliminado a la parte superior de la cola destino
		dataGridView1->Rows[0]->Cells[destino]->Value = nodoEliminado;
		AsignarColorACelda(dataGridView1->Rows[0]->Cells[destino]); // Cambiar el color

		// Decrementar los movimientos restantes
		String^ modo = comboBox_modo->Text;
		if (modo != "Fácil") {
			cantidad_movimientos--;
			ActualizarLabelMovimientos();
		}

		// Verificar si se agotaron los movimientos
		if (cantidad_movimientos == 0) {
			// Detener el temporizador
			timer1->Stop();
			// Ocultar elementos y mostrar cuadro de diálogo
			lbl_movimientos->Visible = false;
			lbl_c->Visible = false;
			lbl_P1->Visible = false;
			txt_origen->Visible = false;
			lbl_P2->Visible = false;
			txt_destino->Visible = false;
			lbl_origen->Visible = false;
			lbl_destino->Visible = false;
			btn_cambiar->Visible = false;
			rbtn_pila->Visible = false;
			rbtn_cola->Visible = false;
			lbl_tiempo_restante->Visible = false;

			MessageBox::Show("¡Se agotaron los movimientos! El juego ha terminado.", "Fin del Juego");
		}

		// Establecer celdas vacías en blanco
		for (int fila = 0; fila < capacidad; fila++) {
			if (dataGridView1->Rows[fila]->Cells[origen]->Value == nullptr) {
				dataGridView1->Rows[fila]->Cells[origen]->Style->BackColor = System::Drawing::Color::White;
			}
			if (dataGridView1->Rows[fila]->Cells[destino]->Value == nullptr) {
				dataGridView1->Rows[fila]->Cells[destino]->Style->BackColor = System::Drawing::Color::White;
			}
		}

		movimiento = String::Format("C{0},C{1}", origen + 1, destino + 1);
	}

	// Agregar el movimiento al registro
	registroMovimientos->AppendLine(movimiento);
}
		
private: System::Void btn_descargarDatos_Click(System::Object^ sender, System::EventArgs^ e) {
			// Crear un cuadro de diálogo para guardar el archivo
			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();

			// Establecer el filtro para los tipos de archivos (en este caso, solo archivos de texto)
			saveFileDialog1->Filter = "Archivos de Texto|*.txt";
			saveFileDialog1->Title = "Guardar Movimientos Realizados";

			// Mostrar el cuadro de diálogo y esperar a que el usuario seleccione la ubicación y el nombre del archivo
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				// Obtener la ubicación seleccionada por el usuario
				String^ nombreArchivo = saveFileDialog1->FileName;

				// Obtener el registro de movimientos como una cadena de texto
				String^ movimientos = registroMovimientos->ToString();

				// Guardar los movimientos en el archivo
				System::IO::File::WriteAllText(nombreArchivo, movimientos);

				// Mostrar un mensaje de éxito
				MessageBox::Show("Movimientos guardados en el archivo: " + nombreArchivo, "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}

	   System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		   // Resta un segundo del tiempo restante en cada tick
		   if (tiempo_limite > 0) {
			   tiempo_limite--;
			   ActualizarLabelTiempo();
		   }
		   else {
			   // El tiempo se ha agotado, detén el temporizador y muestra un cuadro de diálogo
			   timer1->Stop();
			   MessageBox::Show("¡Tiempo agotado!", "Fin del Juego");

			   // Desactiva los controles visibles
			   lbl_movimientos->Visible = false;
			   lbl_c->Visible = false;
			   lbl_P1->Visible = false;
			   txt_origen->Visible = false;
			   lbl_P2->Visible = false;
			   txt_destino->Visible = false;
			   lbl_origen->Visible = false;
			   lbl_destino->Visible = false;
			   btn_cambiar->Visible = false;
			   rbtn_pila->Visible = false;
			   rbtn_cola->Visible = false;
			   lbl_tiempo_restante->Visible = false;
		   }
	   }

	   void ActualizarLabelMovimientos() {
		   lbl_movimientos->Text = "Movimientos restantes: " + cantidad_movimientos;
	   }

	   void ActualizarLabelTiempo() {
		   TimeSpan tiempoRestante = TimeSpan::FromSeconds(tiempo_limite);
		   lbl_tiempo_restante->Text = "Tiempo para jugar: " + tiempoRestante.ToString("hh':'mm':'ss");
	   }






private: System::Void btn_descargarSolucion_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn_terminar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Validar los recuadros que contengan una letra en cada columna
	for (int col = 0; col < dataGridView1->ColumnCount; col++) {
		bool columnaVacia = true;
		for (int fila = 0; fila < dataGridView1->RowCount; fila++) {
			if (dataGridView1->Rows[fila]->Cells[col]->Value != nullptr &&
				dataGridView1->Rows[fila]->Cells[col]->Value->ToString()->Trim() != "") {
				columnaVacia = false;
				break;
			}
		}
		if (columnaVacia) {
			// Esta columna está vacía, mostrar un mensaje y salir
			MessageBox::Show("La columna " + (col + 1) + " está vacía. Por favor, llénala antes de terminar el juego.",
				"Columna Vacía", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
	}

	// Ocultar elementos
	lbl_movimientos->Visible = false;
	lbl_c->Visible = false;
	lbl_P1->Visible = false;
	txt_origen->Visible = false;
	lbl_P2->Visible = false;
	txt_destino->Visible = false;
	lbl_origen->Visible = false;
	lbl_destino->Visible = false;
	btn_cambiar->Visible = false;
	rbtn_pila->Visible = false;
	rbtn_cola->Visible = false;
	btn_descargarDatos->Visible = false;
	lbl_tiempo_restante->Visible = false;
	btn_terminar->Visible = false;

	// Mostrar un cuadro de diálogo de juego terminado
	MessageBox::Show("¡Juego Terminado!", "Juego Terminado", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// Guardar los movimientos en un archivo de texto
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = "Archivos de texto (*.txt)|*.txt";
	saveFileDialog1->Title = "Guardar Movimientos en un Archivo de Texto";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		System::IO::File::WriteAllText(saveFileDialog1->FileName, registroMovimientos->ToString());
	}
}


	   int numPilas = 0;  
	   int capacidadPilas = 0;
	   array<array<String^>^>^ pilasDeColores = gcnew array<array<String^>^>(numPilas);

	  private: System::Void btn_solucion_Click(System::Object^ sender, System::EventArgs^ e) {

		  if (dataGridView1->RowCount == 0 || dataGridView1->ColumnCount == 0) {
			  MessageBox::Show("El DataGridView no tiene filas o columnas");
			  return;
		  }

		  int capacidadPilas = System::Convert::ToInt32(txtCapacidadPilas->Text);

		  if (capacidadPilas > dataGridView1->RowCount || capacidadPilas > dataGridView1->ColumnCount) {
			  MessageBox::Show("La capacidad ingresada excede las dimensiones del DataGridView");
			  return;
		  }

		  // Obtener los colores actuales y sus cantidades
		  Dictionary<String^, int>^ coloresCuenta = gcnew Dictionary<String^, int>();

		  for (int fila = 0; fila < capacidadPilas; fila++) {
			  for (int columna = 0; columna < capacidadPilas; columna++) {

				  if (fila >= dataGridView1->RowCount || columna >= dataGridView1->ColumnCount) {
					  continue; // Salta celdas inválidas
				  }

				  DataGridViewCell^ cell = dataGridView1->Rows[fila]->Cells[columna];

				  if (cell->Value != nullptr) {
					  String^ color = cell->Value->ToString();

					  if (coloresCuenta->ContainsKey(color)) {
						  coloresCuenta[color]++;
					  }
					  else {
						  coloresCuenta[color] = 1;
					  }
				  }

			  }
		  }

		  // Limpiar DataGridView
		  dataGridView1->Rows->Clear();

		  // Recargar colores en orden
		  int filaActual = 0;
		  int columnaActual = 0;

		  for each (KeyValuePair<String^, int> ^ kvp in coloresCuenta) {

			  String^ color = kvp->Key;
			  int cantidad = kvp->Value;

			  for (int i = 0; i < cantidad; i++) {

				  if (columnaActual >= capacidadPilas) {
					  columnaActual = 0;
					  filaActual++;
				  }

				  if (filaActual >= capacidadPilas) {
					  break;
				  }

				  DataGridViewCell^ cell = dataGridView1->Rows[filaActual+1]->Cells[columnaActual+1];

				  cell->Value = color;
				  AsignarColorACelda(cell);

				  columnaActual++;

			  }

			  if (filaActual >= capacidadPilas) {
				  break;
			  }

		  }

		  // Mensaje de finalización
		  MessageBox::Show("¡Solución completada!", "Finalizado",
			  MessageBoxButtons::OK, MessageBoxIcon::Information);

	  }

};
}
