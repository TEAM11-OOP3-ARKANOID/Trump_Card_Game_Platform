#pragma once
#include "OldMaid.h"
#include "GetOldMaidPlayerNum.h"
namespace trump {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private: System::Collections::Generic::List< System::Windows::Forms::Button^> button_list;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		int xPos = 10, yPos = 10;		// 버튼의 x, y 위치
		for (int x = 0; x < 3; x++)		// 버튼 6개 생성
		{
			button_list.Add(gcnew Button); // 버튼 리스트에 버튼을 추가
			button_list[x]->Location = Point(xPos, yPos); // 버튼의 위치
			
			if (x == 0) {
				button_list[x]->Text = "Black Jack";
			}
			else if (x == 1) {
				button_list[x]->Text = "Old Maid";
			}
			else if (x == 2) {
				button_list[x]->Text = "One Card";
			}

			button_list[x]->Size = System::Drawing::Size(90, 50); // 버튼의 크기
			button_list[x]->Click += gcnew System::EventHandler(this, &MyForm::ButtonClick); // 버튼을 클릭했을 때 이벤트
			this->Controls->Add(button_list[x]);
			xPos += 100;
		}
	}
	private: System::Void ButtonClick(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;	// 클릭한 버튼
		//MessageBox::Show(btn->Text);
		if (btn->Text == "Black Jack") {
			//MessageBox::Show("???");
		}
		if (btn->Text == "Old Maid") {
			//OldMaid^ oldmaidForm = gcnew OldMaid;
			//oldmaidForm->Show();
			GetOldMaidPlayerNum^ getplayernumForm = gcnew GetOldMaidPlayerNum;
			getplayernumForm ->Show();
		}
		//게임 창 이동
	}

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 15));
			this->label1->Location = System::Drawing::Point(20, 98);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(277, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tump Card Game Platform";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 161);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
