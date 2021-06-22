#pragma once
#include "AddEmployee.h"
#include "DeleteEmployee.h"
#include "CalculateSalary.h"


namespace ZarplataKursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Admin
	/// </summary>
	public ref class Admin : public System::Windows::Forms::Form
	{
	public:
		Admin(String^ language)
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
		~Admin()
		{
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
	private: System::Windows::Forms::Button^ add_employee_button;
	private: System::Windows::Forms::Button^ payroll_button;

	private: System::Windows::Forms::Button^ fire_employee_button;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Admin::typeid));
			this->reference_button = (gcnew System::Windows::Forms::Button());
			this->color_button = (gcnew System::Windows::Forms::Button());
			this->language_combobox = (gcnew System::Windows::Forms::ComboBox());
			this->language_label = (gcnew System::Windows::Forms::Label());
			this->add_employee_button = (gcnew System::Windows::Forms::Button());
			this->payroll_button = (gcnew System::Windows::Forms::Button());
			this->fire_employee_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// reference_button
			// 
			this->reference_button->Location = System::Drawing::Point(337, 25);
			this->reference_button->Name = L"reference_button";
			this->reference_button->Size = System::Drawing::Size(121, 35);
			this->reference_button->TabIndex = 45;
			this->reference_button->Text = L"Справка";
			this->reference_button->UseVisualStyleBackColor = true;
			// 
			// color_button
			// 
			this->color_button->Location = System::Drawing::Point(12, 25);
			this->color_button->Name = L"color_button";
			this->color_button->Size = System::Drawing::Size(75, 36);
			this->color_button->TabIndex = 44;
			this->color_button->Text = L"Цвет";
			this->color_button->UseVisualStyleBackColor = true;
			// 
			// language_combobox
			// 
			this->language_combobox->FormattingEnabled = true;
			this->language_combobox->Location = System::Drawing::Point(105, 37);
			this->language_combobox->Name = L"language_combobox";
			this->language_combobox->Size = System::Drawing::Size(121, 24);
			this->language_combobox->TabIndex = 43;
			this->language_combobox->SelectedIndexChanged += gcnew System::EventHandler(this, &Admin::language_combobox_SelectedIndexChanged);
			// 
			// language_label
			// 
			this->language_label->AutoSize = true;
			this->language_label->Location = System::Drawing::Point(105, 16);
			this->language_label->Name = L"language_label";
			this->language_label->Size = System::Drawing::Size(94, 17);
			this->language_label->TabIndex = 42;
			this->language_label->Text = L"Смена языка";
			// 
			// add_employee_button
			// 
			this->add_employee_button->Location = System::Drawing::Point(12, 102);
			this->add_employee_button->Name = L"add_employee_button";
			this->add_employee_button->Size = System::Drawing::Size(214, 44);
			this->add_employee_button->TabIndex = 46;
			this->add_employee_button->Text = L"Добавить сотрудника";
			this->add_employee_button->UseVisualStyleBackColor = true;
			this->add_employee_button->Click += gcnew System::EventHandler(this, &Admin::add_employee_button_Click);
			// 
			// payroll_button
			// 
			this->payroll_button->Location = System::Drawing::Point(12, 162);
			this->payroll_button->Name = L"payroll_button";
			this->payroll_button->Size = System::Drawing::Size(445, 44);
			this->payroll_button->TabIndex = 47;
			this->payroll_button->Text = L"Рассчитать зарплату сотрудника";
			this->payroll_button->UseVisualStyleBackColor = true;
			this->payroll_button->Click += gcnew System::EventHandler(this, &Admin::button1_Click);
			// 
			// fire_employee_button
			// 
			this->fire_employee_button->Location = System::Drawing::Point(243, 102);
			this->fire_employee_button->Name = L"fire_employee_button";
			this->fire_employee_button->Size = System::Drawing::Size(214, 44);
			this->fire_employee_button->TabIndex = 48;
			this->fire_employee_button->Text = L"Уволить сотрудника";
			this->fire_employee_button->UseVisualStyleBackColor = true;
			this->fire_employee_button->Click += gcnew System::EventHandler(this, &Admin::fire_employee_button_Click);
			// 
			// Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(469, 437);
			this->Controls->Add(this->fire_employee_button);
			this->Controls->Add(this->payroll_button);
			this->Controls->Add(this->add_employee_button);
			this->Controls->Add(this->reference_button);
			this->Controls->Add(this->color_button);
			this->Controls->Add(this->language_combobox);
			this->Controls->Add(this->language_label);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Admin";
			this->Text = L"Admin";
			this->Load += gcnew System::EventHandler(this, &Admin::Admin_Load);
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
				   this->Text = "Администратор";

				   reference_button->Text = "Справка";
				   color_button->Text = "Цвет";
				   language_label->Text = "Смена языка";

				   fire_employee_button->Text = "Уволить сотрудника";
				   add_employee_button->Text = "Добавить сотрудника";
				   payroll_button->Text = "Начислить зарплату сотруднику";

			   }
			   else if (language_combobox->SelectedItem->ToString() == "Беларуская")
			   {
				   this->Text = "Адміністратар";

				   reference_button->Text = "Даведка";
				   color_button->Text = "Колер";
				   language_label->Text = "Змена мовы";

				   fire_employee_button->Text = "Звольніць супрацоўніка";
				   add_employee_button->Text = "Дадаць супрацоўніка";
				   payroll_button->Text = "Налічыць зарплату супрацоўніку";

			   }
			   else if (language_combobox->SelectedItem->ToString() == "English")
			   {
				   this->Text = "Admin";

				   reference_button->Text = "Reference";
				   color_button->Text = "Color";
				   language_label->Text = "Change language";

				   fire_employee_button->Text = "Fire an employee";
				   add_employee_button->Text = "Add an employee";
				   payroll_button->Text = "Pay salary to an employee";
			   }
		   }
private: System::Void add_employee_button_Click(System::Object^ sender, System::EventArgs^ e) {
	AddEmployee^ form = gcnew AddEmployee(language_combobox->SelectedItem->ToString());
	form->Show();
}
private: System::Void fire_employee_button_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteEmployee^ form = gcnew DeleteEmployee(language_combobox->SelectedItem->ToString());
	form->Show();

}
private: System::Void Admin_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	CalculateSalary^ form = gcnew CalculateSalary(language_combobox->SelectedItem->ToString());
	form->Show();
}
};
}
