#pragma once
#include "service.hpp"

Service service = Service();

namespace Kursovaya {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			service.load();
			
			InitializeComponent();
			
			service.printIndexPage(this->Index);

			service.printPaginator(this->Pages);

			service.printSettings(this->NumNewsOnPage, this->SizeOfText);

			service.printRSSes(this->RSSes);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ Index;
	private: System::Windows::Forms::Button^ Previous;
	protected:


	private: System::Windows::Forms::Button^ Next;

	private: System::Windows::Forms::RichTextBox^ Pages;

	private: System::Windows::Forms::GroupBox^ groupBox1;




	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::MaskedTextBox^ NumNewsOnPage;

	private: System::Windows::Forms::MaskedTextBox^ SizeOfText;
	private: System::Windows::Forms::Button^ update;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::CheckedListBox^ RSSes;
	private: System::Windows::Forms::Button^ deleteRSSes;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::TextBox^ AddRSSes;
	private: System::Windows::Forms::Button^ AddRSS;
	private: System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ category;

	private: System::Windows::Forms::Button^ find;
	private: System::Windows::Forms::Button^ back;
	private: System::Windows::Forms::GroupBox^ groupBox4;













	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Index = (gcnew System::Windows::Forms::RichTextBox());
			this->Previous = (gcnew System::Windows::Forms::Button());
			this->Next = (gcnew System::Windows::Forms::Button());
			this->Pages = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->NumNewsOnPage = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SizeOfText = (gcnew System::Windows::Forms::MaskedTextBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->update = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->AddRSSes = (gcnew System::Windows::Forms::TextBox());
			this->AddRSS = (gcnew System::Windows::Forms::Button());
			this->deleteRSSes = (gcnew System::Windows::Forms::Button());
			this->RSSes = (gcnew System::Windows::Forms::CheckedListBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->back = (gcnew System::Windows::Forms::Button());
			this->category = (gcnew System::Windows::Forms::TextBox());
			this->find = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// Index
			// 
			this->Index->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->Index->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Index->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Index->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Index->Location = System::Drawing::Point(12, 12);
			this->Index->Name = L"Index";
			this->Index->ReadOnly = true;
			this->Index->Size = System::Drawing::Size(655, 716);
			this->Index->TabIndex = 0;
			this->Index->Text = L"";
			// 
			// Previous
			// 
			this->Previous->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)));
			this->Previous->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Previous->Location = System::Drawing::Point(2, 69);
			this->Previous->Name = L"Previous";
			this->Previous->Size = System::Drawing::Size(76, 23);
			this->Previous->TabIndex = 2;
			this->Previous->Text = L"Previous";
			this->Previous->UseVisualStyleBackColor = false;
			this->Previous->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// Next
			// 
			this->Next->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)));
			this->Next->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Next->Location = System::Drawing::Point(96, 69);
			this->Next->Name = L"Next";
			this->Next->Size = System::Drawing::Size(75, 23);
			this->Next->TabIndex = 1;
			this->Next->Text = L"Next";
			this->Next->UseVisualStyleBackColor = false;
			this->Next->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// Pages
			// 
			this->Pages->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->Pages->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Pages->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Pages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Pages->Location = System::Drawing::Point(2, 21);
			this->Pages->Name = L"Pages";
			this->Pages->ReadOnly = true;
			this->Pages->Size = System::Drawing::Size(169, 42);
			this->Pages->TabIndex = 3;
			this->Pages->Text = L"";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Save);
			this->groupBox1->Controls->Add(this->richTextBox1);
			this->groupBox1->Controls->Add(this->NumNewsOnPage);
			this->groupBox1->Controls->Add(this->SizeOfText);
			this->groupBox1->Controls->Add(this->richTextBox3);
			this->groupBox1->Location = System::Drawing::Point(673, 558);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(176, 123);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Settings";
			// 
			// Save
			// 
			this->Save->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->Save->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Save->Location = System::Drawing::Point(9, 87);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(159, 23);
			this->Save->TabIndex = 4;
			this->Save->Text = L"Save";
			this->Save->UseVisualStyleBackColor = false;
			this->Save->Click += gcnew System::EventHandler(this, &Main::Save_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Location = System::Drawing::Point(9, 60);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(104, 20);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"Size of text";
			// 
			// NumNewsOnPage
			// 
			this->NumNewsOnPage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->NumNewsOnPage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NumNewsOnPage->Location = System::Drawing::Point(117, 21);
			this->NumNewsOnPage->Mask = L"00";
			this->NumNewsOnPage->Name = L"NumNewsOnPage";
			this->NumNewsOnPage->PromptChar = ' ';
			this->NumNewsOnPage->Size = System::Drawing::Size(50, 22);
			this->NumNewsOnPage->TabIndex = 1;
			this->NumNewsOnPage->ValidatingType = System::Int32::typeid;
			// 
			// SizeOfText
			// 
			this->SizeOfText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->SizeOfText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SizeOfText->Location = System::Drawing::Point(117, 58);
			this->SizeOfText->Mask = L"00";
			this->SizeOfText->Name = L"SizeOfText";
			this->SizeOfText->PromptChar = ' ';
			this->SizeOfText->Size = System::Drawing::Size(51, 22);
			this->SizeOfText->TabIndex = 2;
			this->SizeOfText->ValidatingType = System::Int32::typeid;
			// 
			// richTextBox3
			// 
			this->richTextBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->richTextBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBox3->Location = System::Drawing::Point(9, 21);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(104, 46);
			this->richTextBox3->TabIndex = 0;
			this->richTextBox3->Text = L"Number of news on page:";
			// 
			// update
			// 
			this->update->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)));
			this->update->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->update->Location = System::Drawing::Point(677, 687);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(172, 41);
			this->update->TabIndex = 5;
			this->update->Text = L"Update";
			this->update->UseVisualStyleBackColor = false;
			this->update->Click += gcnew System::EventHandler(this, &Main::button1_Click_1);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->AddRSSes);
			this->groupBox2->Controls->Add(this->AddRSS);
			this->groupBox2->Controls->Add(this->deleteRSSes);
			this->groupBox2->Controls->Add(this->RSSes);
			this->groupBox2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->groupBox2->Location = System::Drawing::Point(673, 197);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(178, 355);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"RSSes";
			// 
			// AddRSSes
			// 
			this->AddRSSes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->AddRSSes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->AddRSSes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddRSSes->Location = System::Drawing::Point(4, 22);
			this->AddRSSes->Name = L"AddRSSes";
			this->AddRSSes->Size = System::Drawing::Size(169, 22);
			this->AddRSSes->TabIndex = 4;
			// 
			// AddRSS
			// 
			this->AddRSS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)));
			this->AddRSS->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(129)), static_cast<System::Int32>(static_cast<System::Byte>(116)));
			this->AddRSS->FlatAppearance->BorderSize = 0;
			this->AddRSS->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->AddRSS->Location = System::Drawing::Point(4, 49);
			this->AddRSS->Name = L"AddRSS";
			this->AddRSS->Size = System::Drawing::Size(169, 23);
			this->AddRSS->TabIndex = 3;
			this->AddRSS->Text = L"Add RSS";
			this->AddRSS->UseVisualStyleBackColor = false;
			this->AddRSS->Click += gcnew System::EventHandler(this, &Main::AddRSS_Click);
			// 
			// deleteRSSes
			// 
			this->deleteRSSes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)));
			this->deleteRSSes->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->deleteRSSes->Location = System::Drawing::Point(4, 326);
			this->deleteRSSes->Name = L"deleteRSSes";
			this->deleteRSSes->Size = System::Drawing::Size(169, 23);
			this->deleteRSSes->TabIndex = 1;
			this->deleteRSSes->Text = L"Delete chosen RSSes";
			this->deleteRSSes->UseVisualStyleBackColor = false;
			this->deleteRSSes->Click += gcnew System::EventHandler(this, &Main::deleteRSSes_Click);
			// 
			// RSSes
			// 
			this->RSSes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->RSSes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->RSSes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RSSes->FormattingEnabled = true;
			this->RSSes->Location = System::Drawing::Point(4, 78);
			this->RSSes->Name = L"RSSes";
			this->RSSes->Size = System::Drawing::Size(169, 240);
			this->RSSes->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->back);
			this->groupBox3->Controls->Add(this->category);
			this->groupBox3->Controls->Add(this->find);
			this->groupBox3->Location = System::Drawing::Point(675, 112);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(176, 79);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Filter by category";
			// 
			// back
			// 
			this->back->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)));
			this->back->Enabled = false;
			this->back->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->back->Location = System::Drawing::Point(93, 50);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(77, 23);
			this->back->TabIndex = 2;
			this->back->Text = L"Back";
			this->back->UseVisualStyleBackColor = false;
			this->back->Click += gcnew System::EventHandler(this, &Main::back_Click);
			// 
			// category
			// 
			this->category->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)), static_cast<System::Int32>(static_cast<System::Byte>(189)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->category->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->category->Location = System::Drawing::Point(2, 22);
			this->category->Name = L"category";
			this->category->Size = System::Drawing::Size(169, 22);
			this->category->TabIndex = 1;
			// 
			// find
			// 
			this->find->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(83)));
			this->find->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->find->Location = System::Drawing::Point(2, 50);
			this->find->Name = L"find";
			this->find->Size = System::Drawing::Size(76, 23);
			this->find->TabIndex = 0;
			this->find->Text = L"Find!";
			this->find->UseVisualStyleBackColor = false;
			this->find->Click += gcnew System::EventHandler(this, &Main::find_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->Pages);
			this->groupBox4->Controls->Add(this->Previous);
			this->groupBox4->Controls->Add(this->Next);
			this->groupBox4->Location = System::Drawing::Point(675, 4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(176, 102);
			this->groupBox4->TabIndex = 8;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Page:";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(152)));
			this->ClientSize = System::Drawing::Size(860, 740);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->update);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Index);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Main";
			this->Text = L"News aggregator";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Main::Main_FormClosing);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		service.pageNext();
		service.printIndexPage(this->Index);
		service.printPaginator(this->Pages);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		service.pagePrevious();
		service.printIndexPage(this->Index);
		service.printPaginator(this->Pages);
	}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->back->Enabled = false;
	this->category->Text = "";
	service.update();
	service.printIndexPage(this->Index);
	service.printPaginator(this->Pages);
}
private: System::Void deleteRSSes_Click(System::Object^ sender, System::EventArgs^ e) {
	service.deleteRSSes(this->RSSes);
	service.printRSSes(this->RSSes);
}
private: System::Void AddRSS_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->AddRSSes->Text != "")
	{
		service.addRSS(this->AddRSSes->Text);
		service.printRSSes(this->RSSes);
	}
	this->AddRSSes->Text = "";
}
private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->SizeOfText->Text != "")
	{
		service.setSizeFont(System::Convert::ToInt32(this->SizeOfText->Text));
	}
	if (this->NumNewsOnPage->Text != "") {
		service.setNumNewsOnPage(System::Convert::ToInt32(this->NumNewsOnPage->Text));
	}
	service.updateSettings();
	service.printIndexPage(this->Index);
	service.printPaginator(this->Pages);
}
private: System::Void find_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->category->Text != "")
	{
		service.filterByCategory(this->category->Text);
		service.printIndexPage(this->Index);
		service.printPaginator(this->Pages);
		this->back->Enabled = true;
	}
}
private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
	service.backToIndex();
	service.printIndexPage(this->Index);
	service.printPaginator(this->Pages);
	this->back->Enabled = false;
	this->category->Text = "";
}
private: System::Void Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	service.close();
}

};
}
