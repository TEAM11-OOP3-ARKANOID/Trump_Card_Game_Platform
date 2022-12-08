#pragma once
#include "OldMaid.h"
namespace trump {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GetOldMaidPlayerNum�� ���� ����Դϴ�.
	/// </summary>
	public ref class GetOldMaidPlayerNum : public System::Windows::Forms::Form
	{
	public:
		GetOldMaidPlayerNum(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~GetOldMaidPlayerNum()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(86, 112);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(99, 160);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GetOldMaidPlayerNum::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 12));
			this->label1->Location = System::Drawing::Point(53, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Input Playernum 2~5";
			// 
			// GetOldMaidPlayerNum
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"GetOldMaidPlayerNum";
			this->Text = L"GetOldMaidPlayerNum";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Int32 result = 0;
		
		result = System::Convert::ToInt32(textBox1->Text);
		if (result <= 5 && result >= 2) {
			OldMaidGame oldmaidgame(result);
			OldMaid^ oldmaidForm = gcnew OldMaid;
			oldmaidForm->Show();
			this->Close();
		}
		
	}
	//private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//}
	};
}
