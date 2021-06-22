#pragma once
#include "Authentication.h"

namespace ZarplataKursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CalculateSalary
	/// </summary>
	public ref class CalculateSalary : public System::Windows::Forms::Form
	{
	public:
		CalculateSalary(String^ language)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			InitializeEmployees();
			InitializeDates();

			language_combobox->Items->Add("Русский");
			language_combobox->Items->Add("Беларуская");
			language_combobox->Items->Add("English");
			language_combobox->SelectedItem = language;

			current_month_label->Text = DateTime::Now.Month + "." + DateTime::Now.Year;
			calculate_data();

			fio_checkbox->Checked = true;
			search_combobox->SelectedItem = search_combobox->Items[0];
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CalculateSalary()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ red_label;
	protected:
	private: System::Windows::Forms::Label^ white_label;
	private: System::Windows::Forms::Label^ green_label;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ weekend_button;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ charge_salary_button;
	private: System::Windows::Forms::Button^ reference_button;
	private: System::Windows::Forms::Button^ color_button;
	private: System::Windows::Forms::ComboBox^ language_combobox;
	private: System::Windows::Forms::Label^ language_label;

	private:
		String^ reference;
		String^ reference_title;

		String^ salary_msg;
		String^ salary_msg_title;

		String^ salary_charged;
		String^ salary_charged_title;


		String^ no_employees_found_error;
		String^ no_employees_found_error_title;

		String^ login;
		int employee_count = 0;
		int current_employee = 0;
		std::string** employees;

		std::string* days_of_week;

		int hospitals_days = 0;
		int work_days = 0;
		int weekend_work_days = 0;
		double salary = 0;
		double overall = 0;
		
		int to_search = 0;

		bool hospitals;
	private: System::Windows::Forms::Button^ back_button;
	private: System::Windows::Forms::Button^ next_button;
	private: System::Windows::Forms::CheckBox^ union_membership_checkbox;




	private: System::Windows::Forms::Label^ per_day_label;
	private: System::Windows::Forms::Label^ position_label;
	private: System::Windows::Forms::TextBox^ position_textbox;
	private: System::Windows::Forms::Label^ experience_label;


	private: System::Windows::Forms::Label^ wage_rate_label;
	private: System::Windows::Forms::TextBox^ wage_rate_textbox;
	private: System::Windows::Forms::Label^ fio_label;
	private: System::Windows::Forms::TextBox^ fio_textbox;
	private: System::Windows::Forms::TextBox^ experience_textbox;
	private: System::Windows::Forms::Label^ days_label;


	private: System::Windows::Forms::Label^ current_month_label;
	private: System::Windows::Forms::CheckBox^ reward_checkbox;
	private: System::Windows::Forms::Label^ overall_label;

	private: System::Windows::Forms::TextBox^ overall_textbox;


	private: System::Windows::Forms::Label^ rub_label1;
	private: System::Windows::Forms::Label^ swf_fee_label;
	private: System::Windows::Forms::TextBox^ swf_fee_textbox;
	private: System::Windows::Forms::Label^ income_fee_label;
	private: System::Windows::Forms::TextBox^ income_fee_textbox;
	private: System::Windows::Forms::Label^ fee_label;
	private: System::Windows::Forms::Label^ union_fee_label;
	private: System::Windows::Forms::TextBox^ union_fee_textbox;
private: System::Windows::Forms::Label^ salary_label;

private: System::Windows::Forms::TextBox^ salary_textbox;
private: System::Windows::Forms::Label^ rub_label2;
private: System::Windows::Forms::Label^ search_by_label;

private: System::Windows::Forms::Button^ find_button;
private: System::Windows::Forms::ComboBox^ search_combobox;
private: System::Windows::Forms::CheckBox^ number_checkbox;
private: System::Windows::Forms::CheckBox^ fio_checkbox;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CalculateSalary::typeid));
			this->red_label = (gcnew System::Windows::Forms::Label());
			this->white_label = (gcnew System::Windows::Forms::Label());
			this->green_label = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->weekend_button = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->charge_salary_button = (gcnew System::Windows::Forms::Button());
			this->reference_button = (gcnew System::Windows::Forms::Button());
			this->color_button = (gcnew System::Windows::Forms::Button());
			this->language_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->language_label = (gcnew System::Windows::Forms::Label());
			this->back_button = (gcnew System::Windows::Forms::Button());
			this->next_button = (gcnew System::Windows::Forms::Button());
			this->union_membership_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->per_day_label = (gcnew System::Windows::Forms::Label());
			this->position_label = (gcnew System::Windows::Forms::Label());
			this->position_textbox = (gcnew System::Windows::Forms::TextBox());
			this->experience_label = (gcnew System::Windows::Forms::Label());
			this->wage_rate_label = (gcnew System::Windows::Forms::Label());
			this->wage_rate_textbox = (gcnew System::Windows::Forms::TextBox());
			this->fio_label = (gcnew System::Windows::Forms::Label());
			this->fio_textbox = (gcnew System::Windows::Forms::TextBox());
			this->experience_textbox = (gcnew System::Windows::Forms::TextBox());
			this->days_label = (gcnew System::Windows::Forms::Label());
			this->current_month_label = (gcnew System::Windows::Forms::Label());
			this->reward_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->overall_label = (gcnew System::Windows::Forms::Label());
			this->overall_textbox = (gcnew System::Windows::Forms::TextBox());
			this->rub_label1 = (gcnew System::Windows::Forms::Label());
			this->swf_fee_label = (gcnew System::Windows::Forms::Label());
			this->swf_fee_textbox = (gcnew System::Windows::Forms::TextBox());
			this->income_fee_label = (gcnew System::Windows::Forms::Label());
			this->income_fee_textbox = (gcnew System::Windows::Forms::TextBox());
			this->fee_label = (gcnew System::Windows::Forms::Label());
			this->union_fee_label = (gcnew System::Windows::Forms::Label());
			this->union_fee_textbox = (gcnew System::Windows::Forms::TextBox());
			this->salary_label = (gcnew System::Windows::Forms::Label());
			this->salary_textbox = (gcnew System::Windows::Forms::TextBox());
			this->rub_label2 = (gcnew System::Windows::Forms::Label());
			this->search_by_label = (gcnew System::Windows::Forms::Label());
			this->find_button = (gcnew System::Windows::Forms::Button());
			this->search_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->number_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->fio_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// red_label
			// 
			this->red_label->AutoSize = true;
			this->red_label->Location = System::Drawing::Point(51, 627);
			this->red_label->Name = L"red_label";
			this->red_label->Size = System::Drawing::Size(90, 17);
			this->red_label->TabIndex = 69;
			this->red_label->Text = L"Больничный";
			// 
			// white_label
			// 
			this->white_label->AutoSize = true;
			this->white_label->Location = System::Drawing::Point(51, 589);
			this->white_label->Name = L"white_label";
			this->white_label->Size = System::Drawing::Size(73, 17);
			this->white_label->TabIndex = 68;
			this->white_label->Text = L"Выходной";
			// 
			// green_label
			// 
			this->green_label->AutoSize = true;
			this->green_label->Location = System::Drawing::Point(51, 551);
			this->green_label->Name = L"green_label";
			this->green_label->Size = System::Drawing::Size(100, 17);
			this->green_label->TabIndex = 67;
			this->green_label->Text = L"Рабочий день";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Green;
			this->button3->Location = System::Drawing::Point(13, 536);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(32, 32);
			this->button3->TabIndex = 66;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// weekend_button
			// 
			this->weekend_button->BackColor = System::Drawing::Color::White;
			this->weekend_button->Location = System::Drawing::Point(13, 574);
			this->weekend_button->Name = L"weekend_button";
			this->weekend_button->Size = System::Drawing::Size(32, 32);
			this->weekend_button->TabIndex = 65;
			this->weekend_button->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(13, 612);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(32, 32);
			this->button1->TabIndex = 64;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// charge_salary_button
			// 
			this->charge_salary_button->Location = System::Drawing::Point(10, 77);
			this->charge_salary_button->Name = L"charge_salary_button";
			this->charge_salary_button->Size = System::Drawing::Size(266, 44);
			this->charge_salary_button->TabIndex = 61;
			this->charge_salary_button->Text = L"Начислить зарплату";
			this->charge_salary_button->UseVisualStyleBackColor = true;
			this->charge_salary_button->Click += gcnew System::EventHandler(this, &CalculateSalary::charge_salary_button_Click);
			// 
			// reference_button
			// 
			this->reference_button->Location = System::Drawing::Point(10, 713);
			this->reference_button->Name = L"reference_button";
			this->reference_button->Size = System::Drawing::Size(111, 35);
			this->reference_button->TabIndex = 60;
			this->reference_button->Text = L"Справка";
			this->reference_button->UseVisualStyleBackColor = true;
			this->reference_button->Click += gcnew System::EventHandler(this, &CalculateSalary::reference_button_Click);
			// 
			// color_button
			// 
			this->color_button->Location = System::Drawing::Point(10, 17);
			this->color_button->Name = L"color_button";
			this->color_button->Size = System::Drawing::Size(75, 36);
			this->color_button->TabIndex = 59;
			this->color_button->Text = L"Цвет";
			this->color_button->UseVisualStyleBackColor = true;
			this->color_button->Click += gcnew System::EventHandler(this, &CalculateSalary::color_button_Click);
			// 
			// language_combobox
			// 
			this->language_combobox->FormattingEnabled = true;
			this->language_combobox->Location = System::Drawing::Point(103, 29);
			this->language_combobox->Name = L"language_combobox";
			this->language_combobox->Size = System::Drawing::Size(121, 24);
			this->language_combobox->TabIndex = 58;
			this->language_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &CalculateSalary::language_combobox_SelectedIndexChanged);
			// 
			// language_label
			// 
			this->language_label->AutoSize = true;
			this->language_label->Location = System::Drawing::Point(103, 8);
			this->language_label->Name = L"language_label";
			this->language_label->Size = System::Drawing::Size(94, 17);
			this->language_label->TabIndex = 57;
			this->language_label->Text = L"Смена языка";
			// 
			// back_button
			// 
			this->back_button->Location = System::Drawing::Point(10, 480);
			this->back_button->Name = L"back_button";
			this->back_button->Size = System::Drawing::Size(111, 35);
			this->back_button->TabIndex = 70;
			this->back_button->Text = L"Назад";
			this->back_button->UseVisualStyleBackColor = true;
			this->back_button->Click += gcnew System::EventHandler(this, &CalculateSalary::back_button_Click);
			// 
			// next_button
			// 
			this->next_button->Location = System::Drawing::Point(518, 480);
			this->next_button->Name = L"next_button";
			this->next_button->Size = System::Drawing::Size(111, 35);
			this->next_button->TabIndex = 71;
			this->next_button->Text = L"Вперед";
			this->next_button->UseVisualStyleBackColor = true;
			this->next_button->Click += gcnew System::EventHandler(this, &CalculateSalary::next_button_Click);
			// 
			// union_membership_checkbox
			// 
			this->union_membership_checkbox->AutoSize = true;
			this->union_membership_checkbox->Enabled = false;
			this->union_membership_checkbox->Location = System::Drawing::Point(189, 358);
			this->union_membership_checkbox->Name = L"union_membership_checkbox";
			this->union_membership_checkbox->Size = System::Drawing::Size(175, 21);
			this->union_membership_checkbox->TabIndex = 85;
			this->union_membership_checkbox->Text = L"Участие в профсоюзе";
			this->union_membership_checkbox->UseVisualStyleBackColor = true;
			// 
			// per_day_label
			// 
			this->per_day_label->AutoSize = true;
			this->per_day_label->Location = System::Drawing::Point(309, 254);
			this->per_day_label->Name = L"per_day_label";
			this->per_day_label->Size = System::Drawing::Size(66, 17);
			this->per_day_label->TabIndex = 80;
			this->per_day_label->Text = L"руб/день";
			// 
			// position_label
			// 
			this->position_label->AutoSize = true;
			this->position_label->Location = System::Drawing::Point(19, 319);
			this->position_label->Name = L"position_label";
			this->position_label->Size = System::Drawing::Size(81, 17);
			this->position_label->TabIndex = 79;
			this->position_label->Text = L"Должность";
			// 
			// position_textbox
			// 
			this->position_textbox->Location = System::Drawing::Point(189, 316);
			this->position_textbox->Name = L"position_textbox";
			this->position_textbox->ReadOnly = true;
			this->position_textbox->Size = System::Drawing::Size(200, 22);
			this->position_textbox->TabIndex = 78;
			// 
			// experience_label
			// 
			this->experience_label->AutoSize = true;
			this->experience_label->Location = System::Drawing::Point(19, 284);
			this->experience_label->Name = L"experience_label";
			this->experience_label->Size = System::Drawing::Size(41, 17);
			this->experience_label->TabIndex = 77;
			this->experience_label->Text = L"Стаж";
			// 
			// wage_rate_label
			// 
			this->wage_rate_label->AutoSize = true;
			this->wage_rate_label->Location = System::Drawing::Point(19, 252);
			this->wage_rate_label->Name = L"wage_rate_label";
			this->wage_rate_label->Size = System::Drawing::Size(149, 17);
			this->wage_rate_label->TabIndex = 75;
			this->wage_rate_label->Text = L"Ставка оплаты труда";
			// 
			// wage_rate_textbox
			// 
			this->wage_rate_textbox->Location = System::Drawing::Point(189, 249);
			this->wage_rate_textbox->Name = L"wage_rate_textbox";
			this->wage_rate_textbox->ReadOnly = true;
			this->wage_rate_textbox->Size = System::Drawing::Size(114, 22);
			this->wage_rate_textbox->TabIndex = 74;
			// 
			// fio_label
			// 
			this->fio_label->AutoSize = true;
			this->fio_label->Location = System::Drawing::Point(19, 218);
			this->fio_label->Name = L"fio_label";
			this->fio_label->Size = System::Drawing::Size(42, 17);
			this->fio_label->TabIndex = 73;
			this->fio_label->Text = L"ФИО";
			// 
			// fio_textbox
			// 
			this->fio_textbox->Location = System::Drawing::Point(187, 213);
			this->fio_textbox->Name = L"fio_textbox";
			this->fio_textbox->ReadOnly = true;
			this->fio_textbox->Size = System::Drawing::Size(202, 22);
			this->fio_textbox->TabIndex = 72;
			// 
			// experience_textbox
			// 
			this->experience_textbox->Location = System::Drawing::Point(189, 281);
			this->experience_textbox->Name = L"experience_textbox";
			this->experience_textbox->ReadOnly = true;
			this->experience_textbox->Size = System::Drawing::Size(114, 22);
			this->experience_textbox->TabIndex = 86;
			// 
			// days_label
			// 
			this->days_label->AutoSize = true;
			this->days_label->Location = System::Drawing::Point(309, 286);
			this->days_label->Name = L"days_label";
			this->days_label->Size = System::Drawing::Size(40, 17);
			this->days_label->TabIndex = 87;
			this->days_label->Text = L"дней";
			// 
			// current_month_label
			// 
			this->current_month_label->AutoSize = true;
			this->current_month_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->current_month_label->Location = System::Drawing::Point(256, 394);
			this->current_month_label->Name = L"current_month_label";
			this->current_month_label->Size = System::Drawing::Size(133, 31);
			this->current_month_label->TabIndex = 88;
			this->current_month_label->Text = L"Май 2021";
			// 
			// reward_checkbox
			// 
			this->reward_checkbox->AutoSize = true;
			this->reward_checkbox->Location = System::Drawing::Point(327, 145);
			this->reward_checkbox->Name = L"reward_checkbox";
			this->reward_checkbox->Size = System::Drawing::Size(198, 21);
			this->reward_checkbox->TabIndex = 89;
			this->reward_checkbox->Text = L"Премировать сотрудника";
			this->reward_checkbox->UseVisualStyleBackColor = true;
			this->reward_checkbox->CheckedChanged += gcnew System::EventHandler(this, &CalculateSalary::reward_checkbox_CheckedChanged);
			// 
			// overall_label
			// 
			this->overall_label->AutoSize = true;
			this->overall_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->overall_label->Location = System::Drawing::Point(17, 136);
			this->overall_label->Name = L"overall_label";
			this->overall_label->Size = System::Drawing::Size(68, 25);
			this->overall_label->TabIndex = 91;
			this->overall_label->Text = L"Итого";
			// 
			// overall_textbox
			// 
			this->overall_textbox->Location = System::Drawing::Point(111, 140);
			this->overall_textbox->Name = L"overall_textbox";
			this->overall_textbox->ReadOnly = true;
			this->overall_textbox->Size = System::Drawing::Size(128, 22);
			this->overall_textbox->TabIndex = 90;
			// 
			// rub_label1
			// 
			this->rub_label1->AutoSize = true;
			this->rub_label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->rub_label1->Location = System::Drawing::Point(568, 77);
			this->rub_label1->Name = L"rub_label1";
			this->rub_label1->Size = System::Drawing::Size(43, 25);
			this->rub_label1->TabIndex = 95;
			this->rub_label1->Text = L"руб";
			// 
			// swf_fee_label
			// 
			this->swf_fee_label->AutoSize = true;
			this->swf_fee_label->Location = System::Drawing::Point(324, 80);
			this->swf_fee_label->Name = L"swf_fee_label";
			this->swf_fee_label->Size = System::Drawing::Size(49, 17);
			this->swf_fee_label->TabIndex = 94;
			this->swf_fee_label->Text = L"ФЗСН";
			// 
			// swf_fee_textbox
			// 
			this->swf_fee_textbox->Location = System::Drawing::Point(434, 77);
			this->swf_fee_textbox->Name = L"swf_fee_textbox";
			this->swf_fee_textbox->ReadOnly = true;
			this->swf_fee_textbox->Size = System::Drawing::Size(128, 22);
			this->swf_fee_textbox->TabIndex = 93;
			this->swf_fee_textbox->TextChanged += gcnew System::EventHandler(this, &CalculateSalary::swf_fee_textbox_TextChanged);
			// 
			// income_fee_label
			// 
			this->income_fee_label->AutoSize = true;
			this->income_fee_label->Location = System::Drawing::Point(324, 52);
			this->income_fee_label->Name = L"income_fee_label";
			this->income_fee_label->Size = System::Drawing::Size(90, 17);
			this->income_fee_label->TabIndex = 97;
			this->income_fee_label->Text = L"Подоходный";
			// 
			// income_fee_textbox
			// 
			this->income_fee_textbox->Location = System::Drawing::Point(434, 49);
			this->income_fee_textbox->Name = L"income_fee_textbox";
			this->income_fee_textbox->ReadOnly = true;
			this->income_fee_textbox->Size = System::Drawing::Size(128, 22);
			this->income_fee_textbox->TabIndex = 96;
			// 
			// fee_label
			// 
			this->fee_label->AutoSize = true;
			this->fee_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->fee_label->Location = System::Drawing::Point(322, 17);
			this->fee_label->Name = L"fee_label";
			this->fee_label->Size = System::Drawing::Size(77, 25);
			this->fee_label->TabIndex = 99;
			this->fee_label->Text = L"Налоги";
			// 
			// union_fee_label
			// 
			this->union_fee_label->AutoSize = true;
			this->union_fee_label->Location = System::Drawing::Point(324, 108);
			this->union_fee_label->Name = L"union_fee_label";
			this->union_fee_label->Size = System::Drawing::Size(103, 17);
			this->union_fee_label->TabIndex = 101;
			this->union_fee_label->Text = L"Профсоюзный";
			// 
			// union_fee_textbox
			// 
			this->union_fee_textbox->Location = System::Drawing::Point(434, 105);
			this->union_fee_textbox->Name = L"union_fee_textbox";
			this->union_fee_textbox->ReadOnly = true;
			this->union_fee_textbox->Size = System::Drawing::Size(128, 22);
			this->union_fee_textbox->TabIndex = 100;
			// 
			// salary_label
			// 
			this->salary_label->AutoSize = true;
			this->salary_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->salary_label->Location = System::Drawing::Point(18, 170);
			this->salary_label->Name = L"salary_label";
			this->salary_label->Size = System::Drawing::Size(72, 17);
			this->salary_label->TabIndex = 103;
			this->salary_label->Text = L"Зарплата";
			// 
			// salary_textbox
			// 
			this->salary_textbox->Location = System::Drawing::Point(111, 168);
			this->salary_textbox->Name = L"salary_textbox";
			this->salary_textbox->ReadOnly = true;
			this->salary_textbox->Size = System::Drawing::Size(128, 22);
			this->salary_textbox->TabIndex = 102;
			// 
			// rub_label2
			// 
			this->rub_label2->AutoSize = true;
			this->rub_label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->rub_label2->Location = System::Drawing::Point(245, 155);
			this->rub_label2->Name = L"rub_label2";
			this->rub_label2->Size = System::Drawing::Size(43, 25);
			this->rub_label2->TabIndex = 104;
			this->rub_label2->Text = L"руб";
			// 
			// search_by_label
			// 
			this->search_by_label->AutoSize = true;
			this->search_by_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->search_by_label->Location = System::Drawing::Point(456, 194);
			this->search_by_label->Name = L"search_by_label";
			this->search_by_label->Size = System::Drawing::Size(95, 25);
			this->search_by_label->TabIndex = 105;
			this->search_by_label->Text = L"Поиск по";
			// 
			// find_button
			// 
			this->find_button->Location = System::Drawing::Point(461, 344);
			this->find_button->Name = L"find_button";
			this->find_button->Size = System::Drawing::Size(150, 35);
			this->find_button->TabIndex = 107;
			this->find_button->Text = L"Найти";
			this->find_button->UseVisualStyleBackColor = true;
			this->find_button->Click += gcnew System::EventHandler(this, &CalculateSalary::find_button_Click);
			// 
			// search_combobox
			// 
			this->search_combobox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->search_combobox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->search_combobox->FormattingEnabled = true;
			this->search_combobox->Location = System::Drawing::Point(461, 303);
			this->search_combobox->Name = L"search_combobox";
			this->search_combobox->Size = System::Drawing::Size(121, 24);
			this->search_combobox->TabIndex = 108;
			this->search_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &CalculateSalary::search_combobox_SelectedIndexChanged);
			// 
			// number_checkbox
			// 
			this->number_checkbox->AutoSize = true;
			this->number_checkbox->Location = System::Drawing::Point(461, 233);
			this->number_checkbox->Name = L"number_checkbox";
			this->number_checkbox->Size = System::Drawing::Size(149, 21);
			this->number_checkbox->TabIndex = 109;
			this->number_checkbox->Text = L"Табельный номер";
			this->number_checkbox->UseVisualStyleBackColor = true;
			this->number_checkbox->CheckedChanged += gcnew System::EventHandler(this, &CalculateSalary::number_checkbox_CheckedChanged);
			// 
			// fio_checkbox
			// 
			this->fio_checkbox->AutoSize = true;
			this->fio_checkbox->Location = System::Drawing::Point(461, 260);
			this->fio_checkbox->Name = L"fio_checkbox";
			this->fio_checkbox->Size = System::Drawing::Size(64, 21);
			this->fio_checkbox->TabIndex = 110;
			this->fio_checkbox->Text = L"ФИО";
			this->fio_checkbox->UseVisualStyleBackColor = true;
			this->fio_checkbox->CheckedChanged += gcnew System::EventHandler(this, &CalculateSalary::fio_checkbox_CheckedChanged);
			// 
			// CalculateSalary
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(641, 760);
			this->Controls->Add(this->fio_checkbox);
			this->Controls->Add(this->number_checkbox);
			this->Controls->Add(this->search_combobox);
			this->Controls->Add(this->find_button);
			this->Controls->Add(this->search_by_label);
			this->Controls->Add(this->rub_label2);
			this->Controls->Add(this->salary_label);
			this->Controls->Add(this->salary_textbox);
			this->Controls->Add(this->union_fee_label);
			this->Controls->Add(this->union_fee_textbox);
			this->Controls->Add(this->fee_label);
			this->Controls->Add(this->income_fee_label);
			this->Controls->Add(this->income_fee_textbox);
			this->Controls->Add(this->rub_label1);
			this->Controls->Add(this->swf_fee_label);
			this->Controls->Add(this->swf_fee_textbox);
			this->Controls->Add(this->overall_label);
			this->Controls->Add(this->overall_textbox);
			this->Controls->Add(this->reward_checkbox);
			this->Controls->Add(this->current_month_label);
			this->Controls->Add(this->days_label);
			this->Controls->Add(this->experience_textbox);
			this->Controls->Add(this->union_membership_checkbox);
			this->Controls->Add(this->per_day_label);
			this->Controls->Add(this->position_label);
			this->Controls->Add(this->position_textbox);
			this->Controls->Add(this->experience_label);
			this->Controls->Add(this->wage_rate_label);
			this->Controls->Add(this->wage_rate_textbox);
			this->Controls->Add(this->fio_label);
			this->Controls->Add(this->fio_textbox);
			this->Controls->Add(this->next_button);
			this->Controls->Add(this->back_button);
			this->Controls->Add(this->red_label);
			this->Controls->Add(this->white_label);
			this->Controls->Add(this->green_label);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->weekend_button);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->charge_salary_button);
			this->Controls->Add(this->reference_button);
			this->Controls->Add(this->color_button);
			this->Controls->Add(this->language_combobox);
			this->Controls->Add(this->language_label);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CalculateSalary";
			this->Text = L"CalculateSalary";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void language_combobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		change_language();
	}

		private: void change_language()
		{
			if (language_combobox->SelectedItem->ToString() == "Русский")
			{
				this->Text = "Начисление зарплаты";

				reference_title = "Справка";
				reference =
					"В данном окне сотрудник организации отмечает" +
					"дни, когда он работал, болел, или отдыхал." +
					"Эта информация требуется для расчета зарплаты" +
					"и оценке руководства выполненной работы"
					;

				salary_msg_title = "Расчитанная зарплата";
				salary_msg =
					"В этом месяце вы отработали " + (work_days + weekend_work_days) +
					" дней, в том числе " + weekend_work_days + " выходных. Вы находились на " +
					"больничном " + hospitals_days + " дней.\n---------\n" +
					"Ожидаемая зарплата в конце месяца составляет " + salary + " рублей";

				salary_charged_title = "Успех";
				salary_charged = "Зарплата успешно начислена!";

				no_employees_found_error_title = "Ошибка";
				no_employees_found_error = "Ни один сотрудник не рабоает в компании!";
				

				reference_button->Text = "Справка";
				color_button->Text = "Цвет";
				language_label->Text = "Смена языка";

				charge_salary_button->Text = "Начислить зарплату";

				green_label->Text = "Рабочий день";
				white_label->Text = "Выходной";
				red_label->Text = "Больничный";

				next_button->Text = "Дальше";
				back_button->Text = "Назад";

				salary_label->Text = "Зарплата";
				overall_label->Text = "Итого";

				fee_label->Text = "Налоги";
				income_fee_label->Text = "Подоходный";
				swf_fee_label->Text = "ФЗСН";
				union_fee_label->Text = "Профсоюзный";

				rub_label1->Text = "руб.";
				rub_label2->Text = "руб.";
				days_label->Text = "дней";

				search_by_label->Text = "Поиск по";
				find_button->Text = "Найти";
				number_checkbox->Text = "Табельный номер";
				fio_checkbox->Text = "ФИО";

				if (days_of_week != nullptr)
					delete[] days_of_week;
				days_of_week = new std::string[]
				{
					"Пн",
					"Вт",
					"Ср",
					"Чт",
					"Пт",
					"Сб",
					"Вс",
				};
			}
			else if (language_combobox->SelectedItem->ToString() == "Беларуская")
			{
				this->Text = "Налічэнне зарплаты";

				reference_title = "Даведка";
				reference =
					"У дадзеным акне супрацоўнік арганізацыі адзначае" +
					" дні, калі ён працаваў, хварэў, або адпачываў." +
					" Гэтая інфармацыя патрабуецца для разліку зарплаты" +
					" i ацэнцы кіраўніцтва выкананай працы";

				salary_msg_title = "Разлічаная зарплата";
				salary_msg =
					"У гэтым месяцы вы адпрацавалі" + (work_days + weekend_work_days) +
					" дзён, у тым ліку" + weekend_work_days + " выхадных. Вы знаходзіліся на" +
					" бальнічным " + hospitals_days + " дзён. \n--------- \n" +
					"Чаканая заробак у канцы месяца складае " + salary + " рублёў";

				salary_charged_title = "Поспех";
				salary_charged = "Зарплата паспяхова налічаны!";

				no_employees_found_error_title = "Памылка";
				no_employees_found_error = "Ні адзін супрацоўнік не працуе ў кампаніі!";

				next_button->Text = "Далей";
				back_button->Text = "Назад";

				salary_label->Text = "Зарплата";
				overall_label->Text = "Разам";

				fee_label->Text = "Падаткі";
				income_fee_label->Text = "Падаходны";
				swf_fee_label->Text = "ФСАН";
				union_fee_label->Text = "Прафсаюзны";

				reference_button->Text = "Даведка";
				color_button->Text = "Колер";
				language_label->Text = "Змена мовы";

				charge_salary_button->Text = "Налічыць зарплату";

				green_label->Text = "Працоўны дзень";
				white_label->Text = "Выхадны";
				red_label->Text = "Бальнічны";

				rub_label1->Text = "руб.";
				rub_label2->Text = "руб.";
				days_label->Text = "дзён";


				search_by_label->Text = "Пошук па";
				find_button->Text = "Знайсці";
				number_checkbox->Text = "Табельны нумар";
				fio_checkbox->Text = "Прозвішча, імя";

				if (days_of_week != nullptr)
					delete[] days_of_week;
				days_of_week = new std::string[]
				{
					"Пн",
					"Аў",
					"Ср",
					"Чц",
					"Пт",
					"Сб",
					"Нд",
				};

			}
			else if (language_combobox->SelectedItem->ToString() == "English")
			{
				this->Text = "Charging salary";

				reference_title = "Reference";
				reference =
					"In this window, an employee of the organization marks" +
					"days when he worked, was ill, or rested. " +
					"This information is required for payroll calculation" +
					"and management's assessment of the work performed";

				salary_msg_title = "Calculated salary";
				salary_msg =
					"You worked this month " + (work_days + weekend_work_days) +
					" days, including" + weekend_work_days + " weekends. You were on" +
					" sick leave" + hospitals_days + " days. \n---------\n" +
					"The expected salary at the end of the month is " + salary + " rubles";

				no_employees_found_error_title = "Error";
				no_employees_found_error = "There are no employees in this company!";

				salary_charged_title = "Success";
				salary_charged = "Salary was succesfully charged!";

				next_button->Text = "Next";
				back_button->Text = "Back";

				fee_label->Text = "Taxes";
				income_fee_label->Text = "Income";
				swf_fee_label->Text = "SWF";
				union_fee_label->Text = "Union";

				reference_button->Text = "Reference";
				color_button->Text = "Color";
				language_label->Text = "Change language";

				charge_salary_button->Text = "Charge salary";

				green_label->Text = "Work day";
				white_label->Text = "Weekend";
				red_label->Text = "Hospitals";

				salary_label->Text = "Salary";
				overall_label->Text = "Overall";

				rub_label1->Text = "rub";
				rub_label2->Text = "rub";
				days_label->Text = "days";


				search_by_label->Text = "Search by";
				find_button->Text = "Find";
				number_checkbox->Text = "Personnel Number";
				fio_checkbox->Text = "Full name";

				if (days_of_week != nullptr)
					delete[] days_of_week;
				days_of_week = new std::string[]
				{
					"Mo",
					"Tu",
					"We",
					"Th",
					"Fr",
					"Sa",
					"Su",
				};
			}
			int j = 1;

			for (size_t i = 0; i < this->Controls->Count; i++)
			{
				if (this->Controls[i]->Name->ToString() == ("weekday_label" + j.ToString()))
				{
					this->Controls[i]->Text = marshal_as<String^>(days_of_week[j - 1]);
					j++;
				}
			}


			if (language_combobox->SelectedItem->ToString() == "Русский")
			{
				fio_label->Text = "ФИО";
				wage_rate_label->Text = "Ставка оплаты труда";
				per_day_label->Text = "руб./день";
				position_label->Text = "Должность";
				union_membership_checkbox->Text = "Участие в профсоюзе";
				reward_checkbox->Text = "Премировать сотрудника";
			}
			else if (language_combobox->SelectedItem->ToString() == "Беларуская")
			{

				fio_label->Text = "Прозвішча, імя";
				wage_rate_label->Text = "Стаўка аплаты працы";
				per_day_label->Text = "руб./дзень";
				position_label->Text = "Пасаду";
				union_membership_checkbox->Text = "Удзел у прафсаюзе";
				reward_checkbox->Text = "Прэміраваць супрацоўніка";

			}
			else if (language_combobox->SelectedItem->ToString() == "English")
			{
				fio_label->Text = "Full name";
				wage_rate_label->Text = "Wage rate";
				per_day_label->Text = "rub./day";
				position_label->Text = "Position";
				union_membership_checkbox->Text = "Union membership";
				reward_checkbox->Text = "Reward an employee";

			}

		}

		private: void InitializeDates()
		{
			int x = 120, y = 375;
			int size = 32;
			int margin = 38;

			std::map<std::string, int> days_of_week_mp = {
				{"Monday",1},
				{"Tuesday",2},
				{"Wednesday", 3},
				{"Thursday",4},
				{"Friday",5},
				{"Saturday",6},
				{"Sunday",7}
			};

			DateTime dt_start = DateTime(DateTime::Now.Year, DateTime::Now.Month, 1);
			int start = days_of_week_mp[marshal_as<std::string>(dt_start.DayOfWeek.ToString())];
			int end = start + dt_start.DaysInMonth(dt_start.Year, dt_start.Month) - 1;

			for (size_t i = 1; i <= 7; i++)
			{
				Label^ weekday_label = gcnew Label();

				weekday_label->Location = System::Drawing::Point(x + margin / 4, y - margin / 2);
				weekday_label->Name = "weekday_label" + i.ToString();
				weekday_label->Size = System::Drawing::Size(26, 17);

				x += margin;
				this->Controls->Add(weekday_label);

				for (size_t i = 0; i < this-; i++)
				{

				}
			}

			x -= margin * 7;

			//заполнение дат из файла
			std::string path = "workers\\schedule\\";
			path += std::to_string(DateTime::Now.Month) + ".";
			path += std::to_string(DateTime::Now.Year);
			path += " " + employees[current_employee][0] + ".txt";

			std::ifstream schedule_file(path);

			int i = 1;
			if (schedule_file.good())
			{
				//если файл существует	   
				std::string line;
				while (getline(schedule_file, line))
				{
					if (line == "1") {
						create_button(Color::Green, x, y, size, start, end, i);
						if (i % 7 == 0 || i % 7 == 6)
							weekend_work_days++;
						else
							work_days++;
					}
					else if (line == "2") {
						create_button(Color::Red, x, y, size, start, end, i);
						hospitals_days++;
					}
					else {
						create_button(Color::White, x, y, size, start, end, i);
					}


					x += margin;
					if (i % 7 == 0)
					{
						y += margin;
						x -= margin * 7;
					}
					i++;
					if (i > 42)
						break;
				}
			}

			while (i <= 42)
			{
				create_button(Color::White, x, y, size, start, end, i);
				x += margin;
				if (i % 7 == 0)
				{
					y += margin;
					x -= margin * 7;
				}
				i++;
			}

			schedule_file.close();
		}

		private: void create_button(System::Drawing::Color^ color, int x, int y, int size, int start, int end, int current_button)
		{
			Button^ date_button1 = gcnew Button();
			date_button1->Location = System::Drawing::Point(x, y);
			date_button1->Name = "date_button" + current_button.ToString();
			date_button1->Size = System::Drawing::Size(size, size);
			date_button1->UseVisualStyleBackColor = true;
			date_button1->BackColor = (Color)color;
			date_button1->Enabled = false;
			this->Controls->Add(date_button1);
		}

private: System::Void reference_button_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(this, reference, reference_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void color_button_Click(System::Object^ sender, System::EventArgs^ e) {
	ColorDialog^ colorDialog = gcnew ColorDialog(); //вызов окна, где можно выбрать цвет
	colorDialog->Color = this->BackColor; // выбираем текущий цвет по умолчанию

	if (colorDialog->ShowDialog().ToString() == "OK") //если пользоватеьл нажал ОК, то сменяем цвет фона на выбранный цвет
		this->BackColor = colorDialog->Color;
}

	   private: System::Void InitializeEmployees()
	   {
		   //подсчет количества сотрудников
		   std::ifstream users_file("accounts\\Users.txt");
		   std::string line;
		   
		   employee_count = 0;
		   while (getline(users_file, line))
		   {
			   employee_count++;
		   }
		   users_file.close();

		   if (employee_count == 0)
		   {
			   MessageBox::Show(this, no_employees_found_error, no_employees_found_error_title, MessageBoxButtons::OK, MessageBoxIcon::Error);
			   this->Close();
		   }

		   //так как в файле с аккаунтами сотрудников на каждого сотрудника две строчки
		   employee_count /= 2;
	   
		   employees = new std::string*[employee_count];


		   int i = 0;
		   int j = 0;
		   int columns = 0;
		   std::ifstream employees_file("workers\\employees.txt");

		   bool first_employee = true;
		   std::vector<std::string> first_employee_info;

		   while (getline(employees_file, line))
		   {
			   if (line == "---") {	   		   
				   if (first_employee) {
					   first_employee = false;
					   employees[i] = new std::string[columns];
					   for (size_t k = 0; k < columns; k++)
					   {
						   employees[i][k] = first_employee_info[k];
					   }
				   }

				   j = 0;
				   i++;
				   employees[i] = new std::string[columns];
				   continue;
			   }

			   if (first_employee)
			   {
				   columns++;
				   first_employee_info.push_back(line);
			   }
			   else
			   {
				   employees[i][j] = line;
				   j++;
			   }
		   }
		   employees_file.close();
		   	   
		   update_employee_info();
	   }
private: System::Void back_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (current_employee > 0) {
		current_employee--;
		update_employee_info();
	}
	
}

	   private: System::Void next_button_Click(System::Object^ sender, System::EventArgs^ e) {
		   if (current_employee < employee_count-1) {
			   current_employee++;
			   update_employee_info();
		   }
	   }

	   private: void update_employee_info()
	   {
		   String^ fio = marshal_as<String^>(employees[current_employee][2]);
		   String^ wage_rate = marshal_as<String^>(employees[current_employee][3]);
		   
		   int day = std::stoi(employees[current_employee][4].substr(0, 2));
		   int month = std::stoi(employees[current_employee][4].substr(3, 2));
		   int year = std::stoi(employees[current_employee][4].substr(6, 4));
		   DateTime start_date = DateTime(year, month, day);
		   auto difference = DateTime::Now - start_date;

		   String^ experience = difference.Days.ToString();

		   String^ position = marshal_as<String^>(employees[current_employee][5]);
		   bool in_union = employees[current_employee][6] == "1";


		   fio_textbox->Text = fio;
		   wage_rate_textbox->Text = wage_rate;
		   experience_textbox->Text = experience;
		   position_textbox->Text = position;
		   union_membership_checkbox->Checked = in_union;

		   fill_dates();
		   calculate_data();
	   }

			  private: void fill_dates()
			  {
				  //заполнение дат из файла
				  std::string path = "workers\\schedule\\";
				  path += std::to_string(DateTime::Now.Month) + ".";
				  path += std::to_string(DateTime::Now.Year);
				  path += " " + employees[current_employee][0] + ".txt";

				  std::ifstream schedule_file(path);


				  weekend_work_days = 0;
				  work_days = 0;
				  hospitals_days = 0;

				  int i = 1;
				  if (schedule_file.good())
				  {
					  //если файл существует	   
					  std::string line;
					  while (getline(schedule_file, line))
					  {
						  for (size_t j = 0; j < this->Controls->Count; j++)
						  {
							  if (this->Controls[j]->Name == "date_button" + i.ToString())
							  {
								  if (line == "1") {

									  this->Controls[j]->BackColor = Color::Green;
									  if (i % 7 == 0 || i % 7 == 6)
										  weekend_work_days++;
									  else
										  work_days++;
								  }
								  else if (line == "2") {
									  this->Controls[j]->BackColor = Color::Red;
									  hospitals_days++;
								  }
								  else {
									  this->Controls[j]->BackColor = Color::White;
								  }
								  break;		
							  }
						  }
						  i++;
						  if (i > 42)
							  break;
					  }
				  }

				  while (i < 42)
				  {
					  for (size_t j = 0; j < this->Controls->Count; j++)
					  {
						  if (this->Controls[j]->Name == "date_button" + i.ToString())
						  {
							this->Controls[j]->BackColor = Color::White;
							break;
						  }
					  }
					  i++;
					}

				  schedule_file.close();
			  }

private: System::Void charge_salary_button_Click(System::Object^ sender, System::EventArgs^ e) {
	calculate_data();

	std::string to_write = "";
	std::string line;
	std::ifstream awards_file_i("workers\\employees_awards.txt");
	bool login_line = true;
	bool login_found = false;
	while (getline(awards_file_i, line))
	{
		if (login_line)
		{
			login_line = false;
			if (line == employees[current_employee][0])
			{
				login_found = true;
			}
			else
				login_found = false;
		}
		else
		{
			login_line = true;
		}

		if (!login_found)
			to_write += line + "\n";
	}
	awards_file_i.close();

	//запись данных в файл
	std::ofstream awards_file_o("workers\\employees_awards.txt");
	awards_file_o << to_write;
	awards_file_o << employees[current_employee][0] << "\n";
	awards_file_o << (int)reward_checkbox->Checked << "\n";
	awards_file_o.close();

	std::string accruals_path = "workers\\accruals\\";
	accruals_path += marshal_as<std::string>(DateTime::Now.Month + "." + DateTime::Now.Year);
	accruals_path += " ";
	accruals_path += employees[current_employee][0] + ".txt";
	std::ofstream accruals_file(accruals_path);
	accruals_file << salary << "\n" << overall;
	accruals_file.close();

	MessageBox::Show(this, salary_charged, salary_charged_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
}
	   private: void calculate_data()
	   {
		   //ставка оплаты труда работника в день
		   double rate = std::stod(marshal_as<std::string>(wage_rate_textbox->Text));

		   //считаем количество стажа в днях, и за каждый месяц добавляем 3% к зарплате
		   int month = std::stoi(marshal_as<std::string>(wage_rate_textbox->Text));
		   rate *= (1.0 + month * 0.03);

		   salary = (work_days + weekend_work_days * 2 + hospitals_days) * rate;
		   if (reward_checkbox->Checked) this->salary *= 1.2;

		   double income_tax = salary * 0.13;
		   double swf_tax = salary * 0.34;
		   double union_tax = (union_membership_checkbox->Checked) ? salary * 0.01 : 0;

		   income_fee_textbox->Text = income_tax.ToString();
		   swf_fee_textbox->Text = swf_tax.ToString();
		   union_fee_textbox->Text = union_tax.ToString();

		   //прибавляем только то, что должна заплатить организация
		   overall = salary + swf_tax + union_tax;

		   salary_textbox->Text = salary.ToString();
		   overall_textbox->Text = overall.ToString();

		   
	   }
private: System::Void swf_fee_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void reward_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	calculate_data();
}
private: System::Void number_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	search_combobox->Items->Clear();
	if (number_checkbox->Checked) {
		fio_checkbox->Checked = false;
		for (int i = 1; i <= employee_count; i++) {
			search_combobox->Items->Add(i);
		}
	}
	else {
		fio_checkbox_CheckedChanged(nullptr, nullptr);
	}

}
private: System::Void fio_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	search_combobox->Items->Clear();
	if (fio_checkbox->Checked) {
		number_checkbox->Checked = false;
		for (int i = 0; i < employee_count; i++) {
			search_combobox->Items->Add(marshal_as<String^>(employees[i][2]));
		}
	}
	else {
		number_checkbox->Checked = true;
		number_checkbox_CheckedChanged(nullptr, nullptr);
	}
}
private: System::Void find_button_Click(System::Object^ sender, System::EventArgs^ e) {
	update_employee_info();
}
private: System::Void search_combobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	current_employee = search_combobox->SelectedIndex;	
}
};
}
