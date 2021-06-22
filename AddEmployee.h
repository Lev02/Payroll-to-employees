#pragma once
#include <string>
#include <fstream>
#include <msclr\marshal_cppstd.h>
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
	/// Сводка для AddEmployee
	/// </summary>
	public ref class AddEmployee : public System::Windows::Forms::Form
	{
	public:
		AddEmployee(String^ language)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			language_combobox->Items->Add("Русский");
			language_combobox->Items->Add("Беларуская");
			language_combobox->Items->Add("English");
			language_combobox->SelectedItem = language;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddEmployee()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ title_label;
	protected:

	private: System::Windows::Forms::Button^ reference_button;
	private: System::Windows::Forms::Button^ color_button;
	private: System::Windows::Forms::ComboBox^ language_combobox;
	private: System::Windows::Forms::Label^ language_label;
	private: System::Windows::Forms::Label^ fio_label;
	private: System::Windows::Forms::TextBox^ fio_textbox;

	private: System::Windows::Forms::Label^ wage_rate_label;
	private: System::Windows::Forms::TextBox^ wage_rate_textbox;
	private: System::Windows::Forms::DateTimePicker^ employment_datetimepicker;

	private: System::Windows::Forms::Label^ employment_date_label;
	private: System::Windows::Forms::Label^ position_label;
	private: System::Windows::Forms::TextBox^ position_textbox;
	private: System::Windows::Forms::Button^ add_employee_button;
	protected:

	private:
		String^ reference;
		String^ reference_title;

		String^ add_employee_error;
		String^ add_employee_error_title;

		String^ login_exists_error;
		String^ login_exists_error_title;

		String^ add_employee_msg;
		String^ add_employee_msg_title;


	private: System::Windows::Forms::Label^ per_day_label;
	private: System::Windows::Forms::Label^ password_label;
	private: System::Windows::Forms::TextBox^ password_textbox;
	private: System::Windows::Forms::Label^ login_label;
	private: System::Windows::Forms::TextBox^ login_textbox;
	private: System::Windows::Forms::CheckBox^ union_membership_checkbox;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddEmployee::typeid));
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->reference_button = (gcnew System::Windows::Forms::Button());
			this->color_button = (gcnew System::Windows::Forms::Button());
			this->language_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->language_label = (gcnew System::Windows::Forms::Label());
			this->fio_label = (gcnew System::Windows::Forms::Label());
			this->fio_textbox = (gcnew System::Windows::Forms::TextBox());
			this->wage_rate_label = (gcnew System::Windows::Forms::Label());
			this->wage_rate_textbox = (gcnew System::Windows::Forms::TextBox());
			this->employment_datetimepicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->employment_date_label = (gcnew System::Windows::Forms::Label());
			this->position_label = (gcnew System::Windows::Forms::Label());
			this->position_textbox = (gcnew System::Windows::Forms::TextBox());
			this->add_employee_button = (gcnew System::Windows::Forms::Button());
			this->per_day_label = (gcnew System::Windows::Forms::Label());
			this->password_label = (gcnew System::Windows::Forms::Label());
			this->password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->login_label = (gcnew System::Windows::Forms::Label());
			this->login_textbox = (gcnew System::Windows::Forms::TextBox());
			this->union_membership_checkbox = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->Location = System::Drawing::Point(53, 86);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(312, 30);
			this->title_label->TabIndex = 28;
			this->title_label->Text = L"Добавление сотрудника";
			// 
			// reference_button
			// 
			this->reference_button->Location = System::Drawing::Point(303, 21);
			this->reference_button->Name = L"reference_button";
			this->reference_button->Size = System::Drawing::Size(103, 35);
			this->reference_button->TabIndex = 41;
			this->reference_button->Text = L"Справка";
			this->reference_button->UseVisualStyleBackColor = true;
			this->reference_button->Click += gcnew System::EventHandler(this, &AddEmployee::reference_button_Click);
			// 
			// color_button
			// 
			this->color_button->Location = System::Drawing::Point(12, 21);
			this->color_button->Name = L"color_button";
			this->color_button->Size = System::Drawing::Size(75, 36);
			this->color_button->TabIndex = 40;
			this->color_button->Text = L"Цвет";
			this->color_button->UseVisualStyleBackColor = true;
			this->color_button->Click += gcnew System::EventHandler(this, &AddEmployee::color_button_Click);
			// 
			// language_combobox
			// 
			this->language_combobox->FormattingEnabled = true;
			this->language_combobox->Location = System::Drawing::Point(105, 33);
			this->language_combobox->Name = L"language_combobox";
			this->language_combobox->Size = System::Drawing::Size(121, 24);
			this->language_combobox->TabIndex = 39;
			this->language_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &AddEmployee::language_combobox_SelectedIndexChanged);
			// 
			// language_label
			// 
			this->language_label->AutoSize = true;
			this->language_label->Location = System::Drawing::Point(105, 12);
			this->language_label->Name = L"language_label";
			this->language_label->Size = System::Drawing::Size(94, 17);
			this->language_label->TabIndex = 38;
			this->language_label->Text = L"Смена языка";
			// 
			// fio_label
			// 
			this->fio_label->AutoSize = true;
			this->fio_label->Location = System::Drawing::Point(12, 212);
			this->fio_label->Name = L"fio_label";
			this->fio_label->Size = System::Drawing::Size(42, 17);
			this->fio_label->TabIndex = 43;
			this->fio_label->Text = L"ФИО";
			// 
			// fio_textbox
			// 
			this->fio_textbox->Location = System::Drawing::Point(180, 207);
			this->fio_textbox->Name = L"fio_textbox";
			this->fio_textbox->Size = System::Drawing::Size(200, 22);
			this->fio_textbox->TabIndex = 42;
			this->fio_textbox->TextChanged += gcnew System::EventHandler(this, &AddEmployee::fio_textbox_TextChanged);
			// 
			// wage_rate_label
			// 
			this->wage_rate_label->AutoSize = true;
			this->wage_rate_label->Location = System::Drawing::Point(10, 249);
			this->wage_rate_label->Name = L"wage_rate_label";
			this->wage_rate_label->Size = System::Drawing::Size(149, 17);
			this->wage_rate_label->TabIndex = 45;
			this->wage_rate_label->Text = L"Ставка оплаты труда";
			// 
			// wage_rate_textbox
			// 
			this->wage_rate_textbox->Location = System::Drawing::Point(180, 246);
			this->wage_rate_textbox->Name = L"wage_rate_textbox";
			this->wage_rate_textbox->Size = System::Drawing::Size(114, 22);
			this->wage_rate_textbox->TabIndex = 44;
			this->wage_rate_textbox->TextChanged += gcnew System::EventHandler(this, &AddEmployee::wage_rate_textbox_TextChanged);
			// 
			// employment_datetimepicker
			// 
			this->employment_datetimepicker->Location = System::Drawing::Point(180, 286);
			this->employment_datetimepicker->Name = L"employment_datetimepicker";
			this->employment_datetimepicker->Size = System::Drawing::Size(200, 22);
			this->employment_datetimepicker->TabIndex = 46;
			this->employment_datetimepicker->ValueChanged += gcnew System::EventHandler(this, &AddEmployee::employment_datetimepicker_ValueChanged);
			// 
			// employment_date_label
			// 
			this->employment_date_label->AutoSize = true;
			this->employment_date_label->Location = System::Drawing::Point(9, 291);
			this->employment_date_label->Name = L"employment_date_label";
			this->employment_date_label->Size = System::Drawing::Size(165, 17);
			this->employment_date_label->TabIndex = 47;
			this->employment_date_label->Text = L"Дата приема на работу";
			// 
			// position_label
			// 
			this->position_label->AutoSize = true;
			this->position_label->Location = System::Drawing::Point(10, 331);
			this->position_label->Name = L"position_label";
			this->position_label->Size = System::Drawing::Size(81, 17);
			this->position_label->TabIndex = 49;
			this->position_label->Text = L"Должность";
			// 
			// position_textbox
			// 
			this->position_textbox->Location = System::Drawing::Point(180, 328);
			this->position_textbox->Name = L"position_textbox";
			this->position_textbox->Size = System::Drawing::Size(200, 22);
			this->position_textbox->TabIndex = 48;
			this->position_textbox->TextChanged += gcnew System::EventHandler(this, &AddEmployee::position_textbox_TextChanged);
			// 
			// add_employee_button
			// 
			this->add_employee_button->Location = System::Drawing::Point(108, 408);
			this->add_employee_button->Name = L"add_employee_button";
			this->add_employee_button->Size = System::Drawing::Size(189, 44);
			this->add_employee_button->TabIndex = 50;
			this->add_employee_button->Text = L"Добавить";
			this->add_employee_button->UseVisualStyleBackColor = true;
			this->add_employee_button->Click += gcnew System::EventHandler(this, &AddEmployee::add_employee_button_Click);
			// 
			// per_day_label
			// 
			this->per_day_label->AutoSize = true;
			this->per_day_label->Location = System::Drawing::Point(300, 251);
			this->per_day_label->Name = L"per_day_label";
			this->per_day_label->Size = System::Drawing::Size(66, 17);
			this->per_day_label->TabIndex = 51;
			this->per_day_label->Text = L"руб/день";
			// 
			// password_label
			// 
			this->password_label->AutoSize = true;
			this->password_label->Location = System::Drawing::Point(10, 175);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(57, 17);
			this->password_label->TabIndex = 53;
			this->password_label->Text = L"Пароль";
			// 
			// password_textbox
			// 
			this->password_textbox->Location = System::Drawing::Point(180, 170);
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->PasswordChar = '*';
			this->password_textbox->Size = System::Drawing::Size(200, 22);
			this->password_textbox->TabIndex = 52;
			this->password_textbox->TextChanged += gcnew System::EventHandler(this, &AddEmployee::password_textbox_TextChanged);
			// 
			// login_label
			// 
			this->login_label->AutoSize = true;
			this->login_label->Location = System::Drawing::Point(12, 138);
			this->login_label->Name = L"login_label";
			this->login_label->Size = System::Drawing::Size(47, 17);
			this->login_label->TabIndex = 55;
			this->login_label->Text = L"Логин";
			// 
			// login_textbox
			// 
			this->login_textbox->Location = System::Drawing::Point(180, 133);
			this->login_textbox->Name = L"login_textbox";
			this->login_textbox->Size = System::Drawing::Size(200, 22);
			this->login_textbox->TabIndex = 54;
			this->login_textbox->TextChanged += gcnew System::EventHandler(this, &AddEmployee::login_textbox_TextChanged);
			// 
			// union_membership_checkbox
			// 
			this->union_membership_checkbox->AutoSize = true;
			this->union_membership_checkbox->Location = System::Drawing::Point(180, 370);
			this->union_membership_checkbox->Name = L"union_membership_checkbox";
			this->union_membership_checkbox->Size = System::Drawing::Size(175, 21);
			this->union_membership_checkbox->TabIndex = 56;
			this->union_membership_checkbox->Text = L"Участие в профсоюзе";
			this->union_membership_checkbox->UseVisualStyleBackColor = true;
			// 
			// AddEmployee
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(421, 464);
			this->Controls->Add(this->union_membership_checkbox);
			this->Controls->Add(this->login_label);
			this->Controls->Add(this->login_textbox);
			this->Controls->Add(this->password_label);
			this->Controls->Add(this->password_textbox);
			this->Controls->Add(this->per_day_label);
			this->Controls->Add(this->add_employee_button);
			this->Controls->Add(this->position_label);
			this->Controls->Add(this->position_textbox);
			this->Controls->Add(this->employment_date_label);
			this->Controls->Add(this->employment_datetimepicker);
			this->Controls->Add(this->wage_rate_label);
			this->Controls->Add(this->wage_rate_textbox);
			this->Controls->Add(this->fio_label);
			this->Controls->Add(this->fio_textbox);
			this->Controls->Add(this->reference_button);
			this->Controls->Add(this->color_button);
			this->Controls->Add(this->language_combobox);
			this->Controls->Add(this->language_label);
			this->Controls->Add(this->title_label);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddEmployee";
			this->Text = L"AddEmployee";
			this->Load += gcnew System::EventHandler(this, &AddEmployee::AddEmployee_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool login_exists(std::string name)
	{
		std::ifstream users_file("accounts\\users.txt");
		std::string line;
		std::string login, password;
		bool login_line = true;
		while (std::getline(users_file, line))
		{
			if (login_line)
			{
				login_line = false;
				login = line;
				if (login == name)
					return true;
			}
			else
			{
				login_line = true;
			}
		}
		return false;
	}

private: System::Void add_employee_button_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string fio = marshal_as<std::string>(fio_textbox->Text->ToString());
		std::string login = marshal_as<std::string>(login_textbox->Text->ToString());
		std::string password = marshal_as<std::string>(password_textbox->Text->ToString());
		std::string wage_rate = marshal_as<std::string>(wage_rate_textbox->Text->ToString());
		//берём только первые 10 символов, то есть дату, не беря времени
		std::string employment_date = marshal_as<std::string>(employment_datetimepicker->Value.ToString()->Substring(0,10));
		std::string position = marshal_as<std::string>(position_textbox->Text->ToString());
		std::string union_membership = union_membership_checkbox->Checked ? "1" : "0";

		if (fio_textbox->BackColor == Color::Red || fio_textbox->Text->Replace(" ","")->Length == 0
			|| wage_rate_textbox->BackColor == Color::Red || wage_rate_textbox->Text->Replace(" ", "")->Length == 0
			|| position_textbox->BackColor == Color::Red || position_textbox->Text->Replace(" ", "")->Length == 0
			|| login_textbox->BackColor == Color::Red || login_textbox->Text->Replace(" ", "")->Length == 0
			|| password_textbox->BackColor == Color::Red || password_textbox->Text->Replace(" ", "")->Length == 0
			|| employment_datetimepicker->Value > DateTime::Now)
		{
			MessageBox::Show(this, add_employee_error, add_employee_error_title, MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (login_exists(login))
		{
			MessageBox::Show(this, login_exists_error, login_exists_error_title, MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		std::ofstream employees_file("workers\\employees.txt", std::ios::out | std::ios::app);
		employees_file 
			<< login << "\n"
			<< password << "\n"
			<< fio << "\n"
			<< wage_rate << "\n" 
			<< employment_date << "\n" 
			<< position << "\n"
			<< union_membership << "\n"
			<< "---\n";
		employees_file.close();

		std::ofstream users_file("accounts\\users.txt", std::ios::out | std::ios::app);
		users_file
			<< login << "\n"
			<< password << "\n";
		users_file.close();

		

		MessageBox::Show(this, add_employee_msg, add_employee_msg_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

private: System::Void fio_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (fio_textbox->Text->Length == 0)
	{
		fio_textbox->BackColor = Color::Red;
	}
	else
	{
		fio_textbox->BackColor = Color::White;
	}
}

	   private: bool is_digit(std::string s)
	   {
		   try
		   {
			   stod(s);
			   return true;
		   }
		   catch (...)
		   {
			   return false;
		   }
	   }
private: System::Void wage_rate_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (wage_rate_textbox->Text->Length == 0
		|| !is_digit(marshal_as<std::string>(wage_rate_textbox->Text)))
	{
		wage_rate_textbox->BackColor = Color::Red;
	}
	else
	{
		wage_rate_textbox->BackColor = Color::White;
	}
}
private: System::Void position_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (position_textbox->Text->Length == 0)
	{
		position_textbox->BackColor = Color::Red;
	}
	else
	{
		position_textbox->BackColor = Color::White;
	}
}
	   private: System::Void login_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		   if (login_textbox->Text->Length == 0)
		   {
			   login_textbox->BackColor = Color::Red;
		   }
		   else
		   {
			   login_textbox->BackColor = Color::White;
		   }
	   }

			  private: System::Void password_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
				  if (password_textbox->Text->Length == 0)
				  {
					  password_textbox->BackColor = Color::Red;
				  }
				  else
				  {
					  password_textbox->BackColor = Color::White;
				  }
			  }
private: System::Void AddEmployee_Load(System::Object^ sender, System::EventArgs^ e) {
	employment_datetimepicker->Value = DateTime::Now;

	
}
private: System::Void language_combobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	change_language();
}
	   private: void change_language()
	   {
		   if (language_combobox->SelectedItem->ToString() == "Русский")
		   {
			   this->Text = "Добавление сотрудника";

			   reference_title = "Справка";
			   reference =
				   "В данном окне можно добавить сотрудника.";

			   reference_button->Text = "Справка";
			   color_button->Text = "Цвет";
			   language_label->Text = "Смена языка";

			   fio_label->Text = "ФИО";
			   login_label->Text = "Логин";
			   password_label->Text = "Пароль";

			   wage_rate_label->Text = "Ставка оплаты труда";
			   per_day_label->Text = "руб./день";
			   employment_date_label->Text = "Дата приема на работу";
			   position_label->Text = "Должность";
			   union_membership_checkbox->Text = "Участие в профсоюзе";

			   add_employee_button->Text = "Добавить";
			   add_employee_error = "Некоторые поля имели неверный формат";
			   add_employee_error_title = "Ошибка";

			   add_employee_msg = "Сотрудник успешно добавлен";
			   add_employee_msg_title = "Успех";

			   login_exists_error = "Логин уже существует!";
			   login_exists_error_title = "Ошибка";

			   title_label->Text = "Добавление сотрудника";

			   
		   }
		   else if (language_combobox->SelectedItem->ToString() == "Беларуская")
		   {
			   this->Text = "Даданне супрацоўніка";

			   reference_title = "Даведка";
			   reference =
				   "У дадзеным акне можна звольніць супрацоўніка.";

			   reference_button->Text = "Даведка";
			   color_button->Text = "Колер";
			   language_label->Text = "Змена мовы";

			   fio_label->Text = "Прозвішча, імя";
			   login_label->Text = "Лагін";
			   password_label->Text = "Пароль";
			   wage_rate_label->Text = "Стаўка аплаты працы";
			   per_day_label->Text = "руб./дзень";
			   employment_date_label->Text = "Дата прыёму на працу";
			   position_label->Text = "Пасаду";
			   union_membership_checkbox->Text = "Удзел у прафсаюзе";


			   add_employee_button->Text = "Дадаць";
			   add_employee_error = "Некаторыя палі мелі няправільны фармат";
			   add_employee_error_title = "Памылка";

			   add_employee_msg = "Супрацоўнік паспяхова дададзены";
			   add_employee_msg_title = "Поспех";

			   login_exists_error = "Лагін ўжо існуе!";
			   login_exists_error_title = "Памылка";

			   title_label->Text = "Даданне супрацоўніка";

		   }
		   else if (language_combobox->SelectedItem->ToString() == "English")
		   {
			   this->Text = "Adding an employee";

			   reference_title = "Reference";
			   reference =
				   "In this window you can add an employee.";

			   reference_button->Text = "Reference";
			   color_button->Text = "Color";
			   language_label->Text = "Change language";

			   fio_label->Text = "Full name";
			   login_label->Text = "Login";
			   password_label->Text = "Password";
			   wage_rate_label->Text = "Wage rate";
			   per_day_label->Text = "rub./day";
			   employment_date_label->Text = "Employment date";
			   position_label->Text = "Position";
			   union_membership_checkbox->Text = "Union membership";


			   add_employee_button->Text = "Add employee";
			   add_employee_error = "Some textbox had invalid format";
			   add_employee_error_title = "Error";

			   add_employee_msg = "Employee added successfully";
			   add_employee_msg_title = "Success";

			   login_exists_error = "Login already exists!";
			   login_exists_error_title = "Error";

			   title_label->Text = "Adding an employee";

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
private: System::Void employment_datetimepicker_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
