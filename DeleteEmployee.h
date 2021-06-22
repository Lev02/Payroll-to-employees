#pragma once
#include "Authentication.h"
#include <fstream>
#include <string>

namespace ZarplataKursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DeleteEmployee
	/// </summary>
	public ref class DeleteEmployee : public System::Windows::Forms::Form
	{
	public:
		DeleteEmployee(String^ language)
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
		~DeleteEmployee()
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
	private: System::Windows::Forms::Button^ delete_employee_button;



	protected:

	private:
		String^ reference;
		String^ reference_title;

		String^ delete_employee_error;
		String^ delete_employee_error_title;

		String^ delete_employee_msg;
		String^ delete_employee_msg_title;

		String^ login_exists_error;
		String^ login_exists_error_title;




	private: System::Windows::Forms::Label^ login_label;
	private: System::Windows::Forms::TextBox^ login_textbox;
	

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeleteEmployee::typeid));
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->reference_button = (gcnew System::Windows::Forms::Button());
			this->color_button = (gcnew System::Windows::Forms::Button());
			this->language_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->language_label = (gcnew System::Windows::Forms::Label());
			this->delete_employee_button = (gcnew System::Windows::Forms::Button());
			this->login_label = (gcnew System::Windows::Forms::Label());
			this->login_textbox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->Location = System::Drawing::Point(53, 86);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(281, 30);
			this->title_label->TabIndex = 28;
			this->title_label->Text = L"Удаление сотрудника";
			// 
			// reference_button
			// 
			this->reference_button->Location = System::Drawing::Point(296, 21);
			this->reference_button->Name = L"reference_button";
			this->reference_button->Size = System::Drawing::Size(110, 35);
			this->reference_button->TabIndex = 41;
			this->reference_button->Text = L"Справка";
			this->reference_button->UseVisualStyleBackColor = true;
			this->reference_button->Click += gcnew System::EventHandler(this, &DeleteEmployee::reference_button_Click);
			// 
			// color_button
			// 
			this->color_button->Location = System::Drawing::Point(12, 21);
			this->color_button->Name = L"color_button";
			this->color_button->Size = System::Drawing::Size(75, 36);
			this->color_button->TabIndex = 40;
			this->color_button->Text = L"Цвет";
			this->color_button->UseVisualStyleBackColor = true;
			this->color_button->Click += gcnew System::EventHandler(this, &DeleteEmployee::color_button_Click);
			// 
			// language_combobox
			// 
			this->language_combobox->FormattingEnabled = true;
			this->language_combobox->Location = System::Drawing::Point(105, 33);
			this->language_combobox->Name = L"language_combobox";
			this->language_combobox->Size = System::Drawing::Size(121, 24);
			this->language_combobox->TabIndex = 39;
			this->language_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &DeleteEmployee::language_combobox_SelectedIndexChanged_1);
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
			// delete_employee_button
			// 
			this->delete_employee_button->Location = System::Drawing::Point(108, 185);
			this->delete_employee_button->Name = L"delete_employee_button";
			this->delete_employee_button->Size = System::Drawing::Size(189, 44);
			this->delete_employee_button->TabIndex = 50;
			this->delete_employee_button->Text = L"Удалить";
			this->delete_employee_button->UseVisualStyleBackColor = true;
			this->delete_employee_button->Click += gcnew System::EventHandler(this, &DeleteEmployee::delete_employee_button_Click);
			// 
			// login_label
			// 
			this->login_label->AutoSize = true;
			this->login_label->Location = System::Drawing::Point(12, 149);
			this->login_label->Name = L"login_label";
			this->login_label->Size = System::Drawing::Size(47, 17);
			this->login_label->TabIndex = 55;
			this->login_label->Text = L"Логин";
			// 
			// login_textbox
			// 
			this->login_textbox->Location = System::Drawing::Point(180, 144);
			this->login_textbox->Name = L"login_textbox";
			this->login_textbox->Size = System::Drawing::Size(200, 22);
			this->login_textbox->TabIndex = 54;
			this->login_textbox->TextChanged += gcnew System::EventHandler(this, &DeleteEmployee::login_textbox_TextChanged);
			// 
			// DeleteEmployee
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(421, 242);
			this->Controls->Add(this->login_label);
			this->Controls->Add(this->login_textbox);
			this->Controls->Add(this->delete_employee_button);
			this->Controls->Add(this->reference_button);
			this->Controls->Add(this->color_button);
			this->Controls->Add(this->language_combobox);
			this->Controls->Add(this->language_label);
			this->Controls->Add(this->title_label);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"DeleteEmployee";
			this->Text = L"AddEmployee";
			this->Load += gcnew System::EventHandler(this, &DeleteEmployee::DeleteEmployee_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DeleteEmployee_Load(System::Object^ sender, System::EventArgs^ e) {
	}
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
	   

private: System::Void delete_employee_button_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string login = marshal_as<std::string>(login_textbox->Text->ToString());

	if (login == "" || !login_exists(login))
	{
		MessageBox::Show(this, delete_employee_error, delete_employee_error_title, MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	std::string to_write_employees = "";
	std::string to_write_users = "";

	bool login_line = true;
	bool password_line = false;
	bool to_delete = false;

	std::string line;
	std::ifstream employees_file_in("workers\\employees.txt");
	while (getline(employees_file_in, line))
	{	
		if (login_line)
		{
			login_line = false;
			if (line == login)
			{
				to_delete = true;
			}
			else
			{
				to_delete = false;
				to_write_users += line;
				to_write_users += "\n";
			}
			password_line = !to_delete;
		}
		else if (password_line)
		{
			password_line = false;
			to_write_users += line;
			to_write_users += "\n";
		}

		if (to_delete == false)
		{
			to_write_employees += line;
			to_write_employees += "\n";
		}

		if (line == "---")
		{
			login_line = true;
			to_delete = false;
		}
			
	}

	employees_file_in.close();


	std::ofstream employees_file_out("workers\\employees.txt", std::ios::out);
	employees_file_out << to_write_employees;
	employees_file_out.close();

	std::ofstream users_file("accounts\\users.txt", std::ios::out);
	users_file << to_write_users;
	users_file.close();	

	MessageBox::Show(this, delete_employee_msg, delete_employee_msg_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
}


	   private: bool is_int(std::string s)
	   {
		   for (size_t i = 0; i < s.length(); i++)
		   {
			   if (!std::isdigit(s[i]))
				   return false;
		   }
		   return true;
	   }

private: System::Void language_combobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	change_language();
}
	   private: void change_language()
	   {
		   if (language_combobox->SelectedItem->ToString() == "Русский")
		   {
			   this->Text = "Удаление сотрудника";

			   reference_title = "Справка";
			   reference = 
				   "В данном окне можно уволить сотрудника.";
				   
			   reference_button->Text = "Справка";
			   color_button->Text = "Цвет";
			   language_label->Text = "Смена языка";

			   login_label->Text = "Логин";

			   delete_employee_button->Text = "Уволить";
			   delete_employee_error = "Логин не существует в системе!";
			   delete_employee_error_title = "Ошибка";

			   delete_employee_msg = "Сотрудник успешно уволен!";
			   delete_employee_msg_title = "Успех";


			   login_exists_error = "Логин уже существует!";
			   login_exists_error_title = "Ошибка";

			   title_label->Text = "Удаление сотрудника";
		   }
		   else if (language_combobox->SelectedItem->ToString() == "Беларуская")
		   {
			   this->Text = "Выдаленне супрацоўніка";

			   reference_title = "Даведка";
			   reference =
				   "У дадзеным акне можна звольніць супрацоўніка.";

			   reference_button->Text = "Даведка";
			   color_button->Text = "Колер";
			   language_label->Text = "Змена мовы";
		   
			   login_label->Text = "Лагін";

			   delete_employee_button->Text = "Выдаліць";
			   delete_employee_error = "Лагін не існуе ў сістэме!";
			   delete_employee_error_title = "Памылка";

			   delete_employee_msg = "Супрацоўнік паспяхова звольнены!";
			   delete_employee_msg_title = "Поспех";

			   login_exists_error = "Лагін ўжо існуе!";
			   login_exists_error_title = "Памылка";

			   title_label->Text = "Выдаленне супрацоўніка";

		   }
		   else if (language_combobox->SelectedItem->ToString() == "English")
		   {
			   this->Text = "Fire an employee";

			   reference_title = "Reference";
			   reference =
				   "In this window you can fire an employee.";

			   reference_button->Text = "Reference";
			   color_button->Text = "Color";
			   language_label->Text = "Change language";
			   login_label->Text = "Login";

			   delete_employee_button->Text = "Fire an employee";
			   delete_employee_error = "Login does not exist in the system!";
			   delete_employee_error_title = "Error";

			   delete_employee_msg = "Employee was succesfully fired!";
			   delete_employee_msg_title = "Success";

			   login_exists_error = "Login already exists!";
			   login_exists_error_title = "Error";

			   title_label->Text = "Fire an employee";

		   }
	   }
private: System::Void color_button_Click(System::Object^ sender, System::EventArgs^ e) {
	ColorDialog^ colorDialog = gcnew ColorDialog(); //вызов окна, где можно выбрать цвет
	colorDialog->Color = this->BackColor; // выбираем текущий цвет по умолчанию

	if (colorDialog->ShowDialog().ToString() == "OK") //если пользоватеьл нажал ОК, то сменяем цвет фона на выбранный цвет
		this->BackColor = colorDialog->Color;
}
private: System::Void language_combobox_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
	change_language();
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
private: System::Void reference_button_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(this, reference, reference_title, MessageBoxButtons::OK, MessageBoxIcon::Information);
}
};
}
