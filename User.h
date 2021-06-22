#pragma once
#include "Authentication.h"
#include <map>
#include <iostream>
#include <vector>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>

namespace ZarplataKursach {

	using namespace msclr::interop;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для User
	/// </summary>
	public ref class User : public System::Windows::Forms::Form
	{
	public:
		User(String^ login, String^ language)
		{
			this->login = login;

			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			InitializeDates();

			language_combobox->Items->Add("Русский");
			language_combobox->Items->Add("Беларуская");
			language_combobox->Items->Add("English");
			language_combobox->SelectedItem = language;

			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~User()
		{
			save_schedule();

			if (components)
			{
				delete components;
			}
		}

	
	private: System::Windows::Forms::Button^ reference_button;
	protected:
	private: System::Windows::Forms::Button^ color_button;
	private: System::Windows::Forms::ComboBox^ language_combobox;
	private: System::Windows::Forms::Label^ language_label;
	private: System::Windows::Forms::Button^ calculate_salary_button;




	private:
		String^ reference;
		String^ reference_title;

		String^ salary_msg;
		String^ salary_msg_title;

		String^ login;
		
		std::string* days_of_week;

		int hospitals_days = 0;
		int work_days = 0;
		int weekend_work_days = 0;
		double salary = 0;
		bool has_award = false;
		bool hospitals;
	private: System::Windows::Forms::CheckBox^ hospitals_checkbox;
	private: System::Windows::Forms::CheckBox^ workdays_checkbox;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ weekend_button;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ green_label;
	private: System::Windows::Forms::Label^ white_label;
	private: System::Windows::Forms::Label^ red_label;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(User::typeid));
			this->reference_button = (gcnew System::Windows::Forms::Button());
			this->color_button = (gcnew System::Windows::Forms::Button());
			this->language_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->language_label = (gcnew System::Windows::Forms::Label());
			this->calculate_salary_button = (gcnew System::Windows::Forms::Button());
			this->hospitals_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->workdays_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->weekend_button = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->green_label = (gcnew System::Windows::Forms::Label());
			this->white_label = (gcnew System::Windows::Forms::Label());
			this->red_label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// reference_button
			// 
			this->reference_button->Location = System::Drawing::Point(350, 24);
			this->reference_button->Name = L"reference_button";
			this->reference_button->Size = System::Drawing::Size(111, 35);
			this->reference_button->TabIndex = 41;
			this->reference_button->Text = L"Справка";
			this->reference_button->UseVisualStyleBackColor = true;
			this->reference_button->Click += gcnew System::EventHandler(this, &User::reference_button_Click);
			// 
			// color_button
			// 
			this->color_button->Location = System::Drawing::Point(12, 24);
			this->color_button->Name = L"color_button";
			this->color_button->Size = System::Drawing::Size(75, 36);
			this->color_button->TabIndex = 40;
			this->color_button->Text = L"Цвет";
			this->color_button->UseVisualStyleBackColor = true;
			this->color_button->Click += gcnew System::EventHandler(this, &User::color_button_Click);
			// 
			// language_combobox
			// 
			this->language_combobox->FormattingEnabled = true;
			this->language_combobox->Location = System::Drawing::Point(105, 36);
			this->language_combobox->Name = L"language_combobox";
			this->language_combobox->Size = System::Drawing::Size(121, 24);
			this->language_combobox->TabIndex = 39;
			this->language_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &User::language_combobox_SelectedIndexChanged);
			// 
			// language_label
			// 
			this->language_label->AutoSize = true;
			this->language_label->Location = System::Drawing::Point(105, 15);
			this->language_label->Name = L"language_label";
			this->language_label->Size = System::Drawing::Size(94, 17);
			this->language_label->TabIndex = 38;
			this->language_label->Text = L"Смена языка";
			// 
			// calculate_salary_button
			// 
			this->calculate_salary_button->Location = System::Drawing::Point(18, 84);
			this->calculate_salary_button->Name = L"calculate_salary_button";
			this->calculate_salary_button->Size = System::Drawing::Size(214, 44);
			this->calculate_salary_button->TabIndex = 48;
			this->calculate_salary_button->Text = L"Рассчитать зарплату";
			this->calculate_salary_button->UseVisualStyleBackColor = true;
			this->calculate_salary_button->Click += gcnew System::EventHandler(this, &User::calculate_salary_button_Click);
			// 
			// hospitals_checkbox
			// 
			this->hospitals_checkbox->AutoSize = true;
			this->hospitals_checkbox->Location = System::Drawing::Point(18, 143);
			this->hospitals_checkbox->Name = L"hospitals_checkbox";
			this->hospitals_checkbox->Size = System::Drawing::Size(177, 21);
			this->hospitals_checkbox->TabIndex = 49;
			this->hospitals_checkbox->Text = L"Отмечать больничгые";
			this->hospitals_checkbox->UseVisualStyleBackColor = true;
			this->hospitals_checkbox->CheckedChanged += gcnew System::EventHandler(this, &User::hospitals_checkbox_CheckedChanged);
			// 
			// workdays_checkbox
			// 
			this->workdays_checkbox->AutoSize = true;
			this->workdays_checkbox->Checked = true;
			this->workdays_checkbox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->workdays_checkbox->Location = System::Drawing::Point(18, 170);
			this->workdays_checkbox->Name = L"workdays_checkbox";
			this->workdays_checkbox->Size = System::Drawing::Size(183, 21);
			this->workdays_checkbox->TabIndex = 50;
			this->workdays_checkbox->Text = L"Отмечать рабочие дни";
			this->workdays_checkbox->UseVisualStyleBackColor = true;
			this->workdays_checkbox->CheckedChanged += gcnew System::EventHandler(this, &User::workdays_checkbox_CheckedChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(256, 159);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(32, 32);
			this->button1->TabIndex = 51;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// weekend_button
			// 
			this->weekend_button->BackColor = System::Drawing::Color::White;
			this->weekend_button->Location = System::Drawing::Point(256, 121);
			this->weekend_button->Name = L"weekend_button";
			this->weekend_button->Size = System::Drawing::Size(32, 32);
			this->weekend_button->TabIndex = 52;
			this->weekend_button->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Green;
			this->button3->Location = System::Drawing::Point(256, 83);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(32, 32);
			this->button3->TabIndex = 53;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &User::button3_Click);
			// 
			// green_label
			// 
			this->green_label->AutoSize = true;
			this->green_label->Location = System::Drawing::Point(294, 98);
			this->green_label->Name = L"green_label";
			this->green_label->Size = System::Drawing::Size(100, 17);
			this->green_label->TabIndex = 54;
			this->green_label->Text = L"Рабочий день";
			// 
			// white_label
			// 
			this->white_label->AutoSize = true;
			this->white_label->Location = System::Drawing::Point(294, 136);
			this->white_label->Name = L"white_label";
			this->white_label->Size = System::Drawing::Size(73, 17);
			this->white_label->TabIndex = 55;
			this->white_label->Text = L"Выходной";
			// 
			// red_label
			// 
			this->red_label->AutoSize = true;
			this->red_label->Location = System::Drawing::Point(294, 174);
			this->red_label->Name = L"red_label";
			this->red_label->Size = System::Drawing::Size(90, 17);
			this->red_label->TabIndex = 56;
			this->red_label->Text = L"Больничный";
			// 
			// User
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 541);
			this->Controls->Add(this->red_label);
			this->Controls->Add(this->white_label);
			this->Controls->Add(this->green_label);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->weekend_button);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->workdays_checkbox);
			this->Controls->Add(this->hospitals_checkbox);
			this->Controls->Add(this->calculate_salary_button);
			this->Controls->Add(this->reference_button);
			this->Controls->Add(this->color_button);
			this->Controls->Add(this->language_combobox);
			this->Controls->Add(this->language_label);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"User";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"User";
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
				   this->Text = "Пользователь";

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
					   "больничном " + hospitals_days + " дней.\n\n";
				   if (has_award)
					   salary_msg += "Поздравляем! Вы получили премию от начальства в размере 20%\n";
				   else
					   salary_msg += "К сожалению, премии от начальства вы пока что не получали\n---------\n";
					salary_msg += "Ожидаемая зарплата в конце месяца составляет " + salary + " рублей";

				   reference_button->Text = "Справка";
				   color_button->Text = "Цвет";
				   language_label->Text = "Смена языка";

				   calculate_salary_button->Text = "Рассчитать зарплату";

				   green_label->Text = "Рабочий день";
				   white_label->Text = "Выходной";
				   red_label->Text = "Больничный";

				   workdays_checkbox->Text = "Отмечать рабочие дни";
				   hospitals_checkbox->Text = "Отмечать больничные";

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
				   this->Text = "Карыстальнік";

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
					   " бальнічным " + hospitals_days + " дзён. \n";
				   if (has_award)
					   salary_msg += "Віншуем! Вы атрымалі прэмію ад начальства ў памеры 20%\n";
				   else
					   salary_msg += "На жаль, прэміі ад начальства вы пакуль што не атрымлівалі\n---------\n";
					salary_msg += "Чаканая заробак у канцы месяца складае " + salary + " рублёў";

				   reference_button->Text = "Даведка";
				   color_button->Text = "Колер";
				   language_label->Text = "Змена мовы";

				   calculate_salary_button->Text = "Разлічыць зарплату";

				   green_label->Text = "Працоўны дзень";
				   white_label->Text = "Выхадны";
				   red_label->Text = "Бальнічны";

				   workdays_checkbox->Text = "Адзначаць працоўныя дні";
				   hospitals_checkbox->Text = "Адзначаць бальнічныя";


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
				   this->Text = "User";

				   reference_title = "Reference";
				   reference =
					   "In this window, an employee of the organization marks" +
					   "days when he worked, was ill, or rested. " +
					   "This information is required for payroll calculation" +
					   "and management's assessment of the work performed";

				   salary_msg_title = "Calculated salary";
				   salary_msg =
					   "You worked " + (work_days + weekend_work_days) +
					   " days this month, including " + weekend_work_days + " weekends. You were on" +
					   " sick leave for " + hospitals_days + " days. \n";
				   if (has_award)
					   salary_msg += "Congratulations! You received a 20% bonus from your boss\n";
				   else
					   salary_msg += "Unfortunately, you haven't received any bonuses from your bosses yet\n---------\n";
				   salary_msg += "The expected salary at the end of the month is " + salary + " rubles";

				   

				   reference_button->Text = "Reference";
				   color_button->Text = "Color";
				   language_label->Text = "Change language";

				   calculate_salary_button->Text = "Calculate salary";

				   green_label->Text = "Work day";
				   white_label->Text = "Weekend";
				   red_label->Text = "Hospitals";

				   workdays_checkbox->Text = "Mark workdays";
				   hospitals_checkbox->Text = "Mark hospitals";


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
				   if (this->Controls[i]->Name->ToString() == ("weekday_label"+j.ToString()))
				   {
					   this->Controls[i]->Text = marshal_as<String^>(days_of_week[j-1]);
					   j++;
				   }
			   }

		   }
private: System::Void color_button_Click(System::Object^ sender, System::EventArgs^ e) {
	ColorDialog^ colorDialog = gcnew ColorDialog(); //вызов окна, где можно выбрать цвет
	colorDialog->Color = this->BackColor; // выбираем текущий цвет по умолчанию

	if (colorDialog->ShowDialog().ToString() == "OK") //если пользоватеьл нажал ОК, то сменяем цвет фона на выбранный цвет
		this->BackColor = colorDialog->Color;
}
private: System::Void reference_button_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(this, reference, reference_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
}


private: System::Void date_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (((Button^)sender)->BackColor == Color::White)
	{
		if (hospitals_checkbox->Checked)
			((Button^)sender)->BackColor = Color::Red;
		else if (workdays_checkbox->Checked)
		((Button^)sender)->BackColor = Color::Green;
	}
	else if(((Button^)sender)->BackColor != Color::White)
	{
		((Button^)sender)->BackColor = Color::White;
	}
}
	   private: void InitializeDates()
	   {
		   int x = 45, y = 185;
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
	   
		   DateTime dt_start = DateTime(DateTime::Now.Year,DateTime::Now.Month,1);
		   int start = days_of_week_mp[marshal_as<std::string>(dt_start.DayOfWeek.ToString())];
		   int end = start + dt_start.DaysInMonth(dt_start.Year,dt_start.Month) - 1;

		   for (size_t i = 1; i <= 7; i++)
		   {
			   Label^ weekday_label = gcnew Label();

			   weekday_label->Location = System::Drawing::Point(x+margin/4, y-margin/2);
			   weekday_label->Name = "weekday_label" + i.ToString();
			   weekday_label->Size = System::Drawing::Size(26, 17);

			   x += margin;
			   this->Controls->Add(weekday_label);		   
		   }

		   x -= margin * 7;

		   //заполнение дат из файла
		   std::string path = "workers\\schedule\\";
		   path += std::to_string(DateTime::Now.Month) + ".";
		   path += std::to_string(DateTime::Now.Year);
		   path += " " + marshal_as<std::string>(login->ToString()) + ".txt";

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

		private: void save_schedule()
		{
			std::string path = "workers\\schedule\\";
			path += std::to_string(DateTime::Now.Month) + ".";
			path += std::to_string(DateTime::Now.Year);
			path += " " + marshal_as<std::string>(login->ToString()) + ".txt";

			std::ofstream schedule_file(path);
			int j = 1;

			for (size_t i = 0; i < this->Controls->Count; i++)
			{
				if (this->Controls[i]->Name->ToString() == ("date_button" + j.ToString()))
				{
					if (this->Controls[i]->BackColor == Color::White)
					{
						//нерабочий
						schedule_file << 0 << "\n";
					}
					else if (this->Controls[i]->BackColor == Color::Green)
					{
						//рабочий
						schedule_file << 1 << "\n";
					}
					else if (this->Controls[i]->BackColor == Color::Red)
					{
						//больничный
						schedule_file << 2 << "\n";
					}	
					j++;
				}
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
				date_button1->Click += gcnew System::EventHandler(this, &User::date_button_Click);

				if (current_button < start || current_button > end)
					date_button1->Enabled = false;
				else
				{
					date_button1->Text = (current_button - start + 1).ToString();
				}
				this->Controls->Add(date_button1);
			}
private: System::Void hospitals_button_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void workdays_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (workdays_checkbox->Checked)
	{
		hospitals_checkbox->Checked = false;
	}
	else
	{
		hospitals_checkbox->Checked = true;
	}
}
private: System::Void hospitals_checkbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (hospitals_checkbox->Checked)
	{
		workdays_checkbox->Checked = false;
	}
	else
	{
		workdays_checkbox->Checked = true;
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void calculate_salary_button_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ifstream employees_file("workers\\employees.txt");

	std::string line;
	std::vector<std::string> info;
	bool login_line = true;
	bool valid_user = false;
	while (getline(employees_file, line))
	{
		if (login_line)
		{
			login_line = false;
			if (line == marshal_as<std::string>(login->ToString()))
			{
				valid_user = true;
			}
		}

		if (line == "---")
		{
			if (valid_user)
				break;
			login_line = true;		
		}

		if (valid_user)
			info.emplace_back(line);
	}
	employees_file.close();


	//ставка оплаты труда работника в день
	double rate = std::stod(info[3]);
	
	//считаем количество стажа в днях, и за каждый месяц добавляем 3% к зарплате
	int day = std::stoi(info[4].substr(0, 2));
	int month = std::stoi(info[4].substr(3, 2));
	int year = std::stoi(info[4].substr(6, 4));
	DateTime start_date = DateTime(year, month, day);
	auto difference = DateTime::Now - start_date;
	rate *= (1.0 + (difference.Days / 30)*0.03);
	
	//есть ли премия
	has_award = check_award();

	int j = 1;
	weekend_work_days = 0;
	work_days = 0;
	hospitals_days = 0;

	for (size_t i = 0; i < this->Controls->Count; i++)
	{
		if (this->Controls[i]->Name == "date_button" + j.ToString())
		{
			if (this->Controls[i]->BackColor == Color::Green)
			{ 
				if (j % 7 == 0 || j % 7 == 6) {
					this->weekend_work_days++;
				}
				else {
					this->work_days++;
				}				
			}
			else if (this->Controls[i]->BackColor == Color::Red)
			{
				this->hospitals_days++;
			}
			j++;
		}
	}

	this->salary = (this->work_days + this->weekend_work_days * 2 + this->hospitals_days) * rate;
	if (has_award) this->salary *= 1.2;

	change_language();

	MessageBox::Show(this, salary_msg, salary_msg_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
}
	   private: bool check_award()
	   {
		   std::ifstream awards_file("workers\employees_awards.txt");
		   std::string line;

		   bool login_line = true;
		   bool login_found = false;
		   while (getline(awards_file, line))
		   {
			   if (login_line)
			   {
				   login_line = false;
				   if (line == marshal_as<std::string>(login->ToString()))
				   {
					   login_found = true;
				   }
				   else {
					   login_found = false;
				   }		   
			   }
			   else
			   {
				   if (login_found) {
					   //если дата премии совпадает с текущим месяцем
					   if (marshal_as<String^>(line.substr(0, 2)) == DateTime::Now.Month.ToString()
						   && marshal_as<String^>(line.substr(3, 4)) == DateTime::Now.Year.ToString())
					   {
						   return true;
					   }
				   }

				   login_line = true;
			   }
		   }
		   return false;
	   }
};
}

