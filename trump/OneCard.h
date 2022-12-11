#pragma once
#include "OneCardGame.h";
#include <string>
namespace trump {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm1�� ���� ����Դϴ�.
	/// </summary>
	public ref class OneCard : public System::Windows::Forms::Form
	{

	private: System::Collections::Generic::List< System::Windows::Forms::Button^> button_list;
	private: System::Collections::Generic::List< System::Windows::Forms::Button^> card_button_list;


	private: bool isUserTurn = false;
	private: bool isPlayed = false;

	private: System::Void OneCard_Load(System::Object^ sender, System::EventArgs^ e) {


		textBox1->AppendText("Lets start the game" + "\r\n"); // �̷������� ����Ʈ
		//playercard[0]->print_winform(textBox1);
		//printf("\n");




		for (int x = 0; x < 2; x++)		// ��ư 6�� ����
		{
			button_list.Add(gcnew Button); // ��ư ����Ʈ�� ��ư�� �߰�
			button_list[x]->Location = Point(90 + 110 * x, 10); // ��ư�� ��ġ

			if (x == 0) {
				button_list[x]->Text = "Start";
			}
			else if (x == 1) {
				button_list[x]->Text = "Continue";
			}
			
			button_list[x]->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 8));
			button_list[x]->Size = System::Drawing::Size(100, 50); // ��ư�� ũ��
			button_list[x]->Click += gcnew System::EventHandler(this, &OneCard::ButtonClick); // ��ư�� Ŭ������ �� �̺�Ʈ
			this->Controls->Add(button_list[x]);
		}

		int xPos = 10, yPos = 65;		// ��ư�� x, y ��ġ

		for (int x = 0; x < 15; x++)		// ��ư 6�� ����
		{
			card_button_list.Add(gcnew Button); // ��ư ����Ʈ�� ��ư�� �߰�
			card_button_list[x]->Location = Point(xPos, yPos); // ��ư�� ��ġ

			card_button_list[x]->Text = gcnew String(("card " + std::to_string(x + 1)).c_str());
			
			card_button_list[x]->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 8));
			card_button_list[x]->Size = System::Drawing::Size(40, 40); // ��ư�� ũ��
			card_button_list[x]->Click += gcnew System::EventHandler(this, &OneCard::ButtonClick); // ��ư�� Ŭ������ �� �̺�Ʈ
			this->Controls->Add(card_button_list[x]);
			xPos += 45;
		}
	}
	private: System::Void ButtonClick(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;	// Ŭ���� ��ư
		//MessageBox::Show(btn->Text);
		if (btn->Text == "Start") {
			srand(time(nullptr));

			//for (int i = 0; i < onecard->currentPlayer[0].currentHand.size(); i++) {

			//	//card_button_list[i]->Text = gcnew String(onecard->currentPlayer[0].currentHand[i].printString().c_str());
			//	card_button_list[i]->Text = gcnew String(std::to_string(i).c_str());
			//}

			onecard->setGame(textBox1);

			onecard->playCardCpu(textBox1);

			textBox1->AppendText("My Hand: ");
			for (int i = 0; i < onecard->currentPlayer[0].currentHand.size(); i++) {
				onecard->currentPlayer[0].currentHand[i].print_winform(textBox1);
				textBox1->AppendText(" ");
			}
			textBox1->AppendText("\r\n");

			isUserTurn = true;
		}
		if (btn->Text == "Continue") {
			if (!isPlayed) {
				onecard->currentPlayer[0].currentHand.push_back(*onecard->currentDeck.DrawCard());
			}
			isPlayed = false;
			onecard->playCardCpu(textBox1);
			if (onecard->gameEnd) {
				return;
			}
			textBox1->AppendText("My Hand: ");
			for (int i = 0; i < onecard->currentPlayer[0].currentHand.size(); i++) {
				onecard->currentPlayer[0].currentHand[i].print_winform(textBox1);
				textBox1->AppendText(" ");
			}
			textBox1->AppendText("\r\n");
			isUserTurn = true;
		}
		for (int i = 0; i < 15; i++) {
			if (i >= onecard->currentPlayer[0].currentHand.size()) {
				return;
			}
			if (btn->Text == ("card " + (i + 1))) {
				isPlayed = true;
				//textBox1->AppendText(gcnew String(std::to_string(i).c_str()));
				if (onecard->isAvailable(onecard->currentPlayer[0].currentHand[i])) {
					onecard->currentTrash.push_back(onecard->currentPlayer[0].PlayCard(i));
					if (onecard->currentPlayer[0].currentHand.size() == 0) {
						textBox1->AppendText("You won");
						return;
					}
					for (int j = 0; j < onecard->currentPlayer[0].currentHand.size(); j++) {
						onecard->currentPlayer[0].currentHand[j].print_winform(textBox1);
						textBox1->AppendText(" ");
					}

					textBox1->AppendText("\r\n");
					for (int j = 0; j < onecard->currentTrash.size(); j++) {
						onecard->currentTrash[j].print_winform(textBox1);
						textBox1->AppendText(" ");
					}

					textBox1->AppendText("\r\n");
				}
				else {
					textBox1->AppendText("not available");
					textBox1->AppendText("\r\n");
				}
			}
		}
	}
	//private: System::Windows::Forms::TextBox^ textBox1;

	// added until here

	private: System::Windows::Forms::TextBox^ textBox1;

	public:
		OneCardGame* onecard;
		OneCard(void)
		{
			onecard = new OneCardGame();
			
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}
	
	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~OneCard()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>)
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBox1->Location = System::Drawing::Point(29, 114);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(730, 300);
			this->textBox1->TabIndex = 0;
			this->textBox1->Multiline = true;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Kristen ITC", 8));
			textBox1->AppendText("Lets start the game" + "\r\n");


			// One Card
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 450);
			this->Controls->Add(this->textBox1);
			this->Name = L"OneCard";
			this->Text = L"OneCard";
			this->Load += gcnew System::EventHandler(this, &OneCard::OneCard_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	};
}
