#pragma once

namespace lb23 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Line", L"Rectangle", L"Fill rectangle", L"Ellipse",
					L"Fill ellipse", L"Sector", L"Star"
			});
			this->listBox1->Location = System::Drawing::Point(301, 233);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(115, 95);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 327);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		array<Point>^ p;
		p = gcnew array<Point>(11);
		p[0].X = 150; p[0].Y = 20;
		p[1].X = 120; p[1].Y = 90;
		p[2].X = 50; p[2].Y = 100;
		p[3].X = 120; p[3].Y = 150;
		p[4].X = 110; p[4].Y = 220;
		p[5].X = 160; p[5].Y = 180;
		p[6].X = 240; p[6].Y = 210;
		p[7].X = 220; p[7].Y = 140;
		p[8].X = 260; p[8].Y = 90;
		p[9].X = 190; p[9].Y = 80;
		p[10].X = 150; p[10].Y = 20;
		Graphics^ graf = CreateGraphics();
		//Створення пера
		Pen^ pn = gcnew System::Drawing::Pen(Color::Green, 4);
		//brush
		Brush^ br = gcnew System::Drawing::SolidBrush(Color::Blue);
		//Очистити форму
		graf->Clear(SystemColors::Control);

		switch (listBox1->SelectedIndex)
		{
		case 0:graf->DrawLine(pn, 150, 40, 200, 150);
			break;
		case 1:graf->DrawRectangle(pn, 50, 50, 100, 50);
			break;
		case 2:graf->FillRectangle(br, 50, 140, 50, 130);
			break;
		case 3:graf->DrawEllipse(pn, 150, 100, 150, 110);
			break;
		case 4:graf->FillEllipse(br, 150, 100, 150, 110);
			break;
		case 5:graf->FillPie(br, 150, 40, 150, 150, 45, 90);
			break;
		case 6:  graf->FillPolygon(br, p);
		default:
			break;
		}


	}
	};
}