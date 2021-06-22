#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>

#include "User.h"
#include "Admin.h"


namespace ZarplataKursach {

	using namespace msclr::interop;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Authentication
	/// </summary>
	public ref class Authentication : public System::Windows::Forms::Form
	{
	public:
		Authentication(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			language_combobox->Items->Add("Русский");
			language_combobox->Items->Add("Беларуская");
			language_combobox->Items->Add("English");
			language_combobox->SelectedItem = language_combobox->Items[0];
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Authentication()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ color_button;
	protected:
	private: System::Windows::Forms::ComboBox^ rank_combobox;
	private: System::Windows::Forms::Button^ signin_button;
	private: System::Windows::Forms::Label^ password_label;
	private: System::Windows::Forms::ComboBox^ language_combobox;
	private: System::Windows::Forms::Label^ language_label;
	private: System::Windows::Forms::Label^ login_label;
	private: System::Windows::Forms::TextBox^ password_textbox;
	private: System::Windows::Forms::Label^ signin_label;
	private: System::Windows::Forms::TextBox^ login_textbox;
	private: System::Windows::Forms::Button^ reference_button;

	private:
		String^ reference;
		String^ reference_title;
		String^ signin_error;
		String^ signin_error_title;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Authentication::typeid));
			this->color_button = (gcnew System::Windows::Forms::Button());
			this->rank_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->signin_button = (gcnew System::Windows::Forms::Button());
			this->password_label = (gcnew System::Windows::Forms::Label());
			this->language_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->language_label = (gcnew System::Windows::Forms::Label());
			this->login_label = (gcnew System::Windows::Forms::Label());
			this->password_textbox = (gcnew System::Windows::Forms::TextBox());
			this->signin_label = (gcnew System::Windows::Forms::Label());
			this->login_textbox = (gcnew System::Windows::Forms::TextBox());
			this->reference_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// color_button
			// 
			this->color_button->Location = System::Drawing::Point(12, 28);
			this->color_button->Name = L"color_button";
			this->color_button->Size = System::Drawing::Size(75, 36);
			this->color_button->TabIndex = 36;
			this->color_button->Text = L"Цвет";
			this->color_button->UseVisualStyleBackColor = true;
			this->color_button->Click += gcnew System::EventHandler(this, &Authentication::color_button_Click);
			// 
			// rank_combobox
			// 
			this->rank_combobox->FormattingEnabled = true;
			this->rank_combobox->Location = System::Drawing::Point(126, 138);
			this->rank_combobox->Name = L"rank_combobox";
			this->rank_combobox->Size = System::Drawing::Size(200, 24);
			this->rank_combobox->TabIndex = 34;
			// 
			// signin_button
			// 
			this->signin_button->Location = System::Drawing::Point(126, 278);
			this->signin_button->Name = L"signin_button";
			this->signin_button->Size = System::Drawing::Size(189, 44);
			this->signin_button->TabIndex = 33;
			this->signin_button->Text = L"Войти";
			this->signin_button->UseVisualStyleBackColor = true;
			this->signin_button->Click += gcnew System::EventHandler(this, &Authentication::signin_button_Click);
			// 
			// password_label
			// 
			this->password_label->AutoSize = true;
			this->password_label->Location = System::Drawing::Point(46, 223);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(57, 17);
			this->password_label->TabIndex = 32;
			this->password_label->Text = L"Пароль";
			// 
			// language_combobox
			// 
			this->language_combobox->FormattingEnabled = true;
			this->language_combobox->Location = System::Drawing::Point(105, 40);
			this->language_combobox->Name = L"language_combobox";
			this->language_combobox->Size = System::Drawing::Size(121, 24);
			this->language_combobox->TabIndex = 31;
			this->language_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &Authentication::language_combobox_SelectedIndexChanged);
			// 
			// language_label
			// 
			this->language_label->AutoSize = true;
			this->language_label->Location = System::Drawing::Point(105, 19);
			this->language_label->Name = L"language_label";
			this->language_label->Size = System::Drawing::Size(94, 17);
			this->language_label->TabIndex = 30;
			this->language_label->Text = L"Смена языка";
			// 
			// login_label
			// 
			this->login_label->AutoSize = true;
			this->login_label->Location = System::Drawing::Point(47, 181);
			this->login_label->Name = L"login_label";
			this->login_label->Size = System::Drawing::Size(47, 17);
			this->login_label->TabIndex = 29;
			this->login_label->Text = L"Логин";
			// 
			// password_textbox
			// 
			this->password_textbox->Location = System::Drawing::Point(126, 223);
			this->password_textbox->Name = L"password_textbox";
			this->password_textbox->PasswordChar = '*';
			this->password_textbox->Size = System::Drawing::Size(200, 22);
			this->password_textbox->TabIndex = 28;
			// 
			// signin_label
			// 
			this->signin_label->AutoSize = true;
			this->signin_label->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signin_label->Location = System::Drawing::Point(161, 89);
			this->signin_label->Name = L"signin_label";
			this->signin_label->Size = System::Drawing::Size(136, 30);
			this->signin_label->TabIndex = 27;
			this->signin_label->Text = L"Войти как";
			// 
			// login_textbox
			// 
			this->login_textbox->Location = System::Drawing::Point(126, 181);
			this->login_textbox->Name = L"login_textbox";
			this->login_textbox->Size = System::Drawing::Size(200, 22);
			this->login_textbox->TabIndex = 26;
			// 
			// reference_button
			// 
			this->reference_button->Location = System::Drawing::Point(307, 28);
			this->reference_button->Name = L"reference_button";
			this->reference_button->Size = System::Drawing::Size(99, 35);
			this->reference_button->TabIndex = 37;
			this->reference_button->Text = L"Справка";
			this->reference_button->UseVisualStyleBackColor = true;
			this->reference_button->Click += gcnew System::EventHandler(this, &Authentication::reference_button_Click);
			// 
			// Authentication
			// 
			this->AcceptButton = this->signin_button;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 354);
			this->Controls->Add(this->reference_button);
			this->Controls->Add(this->color_button);
			this->Controls->Add(this->rank_combobox);
			this->Controls->Add(this->signin_button);
			this->Controls->Add(this->password_label);
			this->Controls->Add(this->language_combobox);
			this->Controls->Add(this->language_label);
			this->Controls->Add(this->login_label);
			this->Controls->Add(this->password_textbox);
			this->Controls->Add(this->signin_label);
			this->Controls->Add(this->login_textbox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Authentication";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Authentication";
			this->Load += gcnew System::EventHandler(this, &Authentication::Authentication_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void language_combobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		change_language();
	}

		   private: void change_language()
		   {
			   int selected_index = rank_combobox->SelectedIndex;
			   if (language_combobox->SelectedItem->ToString() == "Русский")
			   {
				   this->Text = "Авторизация";

				   reference_title = "Справка";
				   reference =
					   "В данном окне происходит авторизация пользователя.\n" +
					   "В систему можно войти как сотрудник организации, либо как администратор";


				   reference_button->Text = "Справка";
				   color_button->Text = "Цвет";
				   language_label->Text = "Смена языка";
				   signin_label->Text = "Войти как";
				   signin_button->Text = "Вход";
				   login_label->Text = "Логин";
				   password_label->Text = "Пароль";

				   reference_title = "Справка";

				   signin_error = "Неправильный логин либо пароль!";
				   signin_error_title = "Ошибка входа";	

				   rank_combobox->Items->Clear();
				   rank_combobox->Items->Add("Пользователь");
				   rank_combobox->Items->Add("Администратор");				   
			   }
			   else if (language_combobox->SelectedItem->ToString() == "Беларуская")
			   {
				   this->Text = "Аўтарызацыя";

				   reference_title = "Даведка";
				   reference =
					   "У дадзеным акне адбываецца аўтарызацыя карыстальніка.\n" +
					   "У сістэму можна ўвайсці як супрацоўнік арганізацыі, альбо як адміністратар";

				   reference_button->Text = "Даведка";
				   color_button->Text = "Колер";
				   language_label->Text = "Змена мовы";
				   signin_label->Text = "Увайсці як";
				   signin_button->Text = "Уваход";
				   login_label->Text = "Лагін";
				   password_label->Text = "Пароль";

				   reference_title = "Даведка";

				   signin_error = "Няправільны лагін альбо пароль!";
				   signin_error_title = "Памылка ўваходу";

				   rank_combobox->Items->Clear();
				   rank_combobox->Items->Add("Карыстальнік");
				   rank_combobox->Items->Add("Адміністратар");
			   }
			   else if (language_combobox->SelectedItem->ToString() == "English")
			   {
				   this->Text = "Authorization";

				   reference_title = "Reference";
				   reference =
					   "In this window, the user is authorized.\n" +
					   "You can enter the system as an employee of the organization, or as an administrator";

				   reference_button->Text = "Reference";
				   color_button->Text = "Color";
				   language_label->Text = "Change language";
				   signin_label->Text = "Sign in as";
				   signin_button->Text = "Enter";
				   login_label->Text = "Login";
				   password_label->Text = "Password";

				   reference_title = "Reference";

				   signin_error = "Wrong login or password!";
				   signin_error_title = "Sign in error";

				   rank_combobox->Items->Clear();
				   rank_combobox->Items->Add("User");
				   rank_combobox->Items->Add("Admin");

			   }
			   if (selected_index != -1)
				   rank_combobox->SelectedItem = rank_combobox->Items[selected_index];
			   else
				   rank_combobox->SelectedItem = rank_combobox->Items[0];
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

	private: bool validate(std::string type)
	{
		std::ifstream users_file("accounts\\" + type + ".txt");
		if (users_file.is_open() == false)
		{
			return false;
		}
		std::string line;
		std::string login, password;
		bool login_line = true;
		while (std::getline(users_file, line))
		{
			if (login_line)
			{
				login_line = false;
				login = line;
			}
			else
			{
				login_line = true;
				password = line;
				if (marshal_as<String^>(login) == login_textbox->Text
					&& marshal_as<String^>(password) == password_textbox->Text)
				{
					return true;
				}
			}		
		}
		return false;
	}

private: System::Void signin_button_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ language = language_combobox->SelectedItem->ToString();
	Form^ form;
	bool success=false;

	if (rank_combobox->SelectedIndex == 0)
	{
		success = validate("Users");
		if (success)
			form = gcnew User(login_textbox->Text, language);
	}
	else if (rank_combobox->SelectedIndex == 1)
	{
		success = validate("Admins");
		if (success)
			form = gcnew Admin(language);
	}
		
	if (!success)
		MessageBox::Show(this, signin_error, signin_error_title, MessageBoxButtons::OK, MessageBoxIcon::Error);
	else
		form->Show();
}
private: System::Void Authentication_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
