#pragma once

namespace NumberGuessingGame {

    using namespace System;

    public ref class MyForm : public System::Windows::Forms::Form {
    public:
        MyForm() {
            InitializeComponent();
            InitializeGame();
        }

    protected:
        ~MyForm() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ txtGuess;
        System::Windows::Forms::Button^ btnGuess;
        System::Windows::Forms::Label^ lblResult;
        int secretNumber;
        System::Windows::Forms::Label^ labelTitle;
        System::Windows::Forms::Label^ labelInstruction;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->txtGuess = (gcnew System::Windows::Forms::TextBox());
            this->btnGuess = (gcnew System::Windows::Forms::Button());
            this->lblResult = (gcnew System::Windows::Forms::Label());
            this->labelTitle = (gcnew System::Windows::Forms::Label());
            this->labelInstruction = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // txtGuess
            // 
            this->txtGuess->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18));
            this->txtGuess->Location = System::Drawing::Point(370, 215);
            this->txtGuess->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->txtGuess->Multiline = true;
            this->txtGuess->Name = L"txtGuess";
            this->txtGuess->Size = System::Drawing::Size(347, 50);
            this->txtGuess->TabIndex = 0;
            this->txtGuess->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // btnGuess
            // 
            this->btnGuess->BackColor = System::Drawing::Color::DodgerBlue;
            this->btnGuess->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnGuess->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->btnGuess->ForeColor = System::Drawing::Color::White;
            this->btnGuess->Location = System::Drawing::Point(418, 271);
            this->btnGuess->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->btnGuess->Name = L"btnGuess";
            this->btnGuess->Size = System::Drawing::Size(246, 50);
            this->btnGuess->TabIndex = 1;
            this->btnGuess->Text = L"Check";
            this->btnGuess->UseVisualStyleBackColor = false;
            this->btnGuess->Click += gcnew System::EventHandler(this, &MyForm::btnGuess_Click);
            // 
            // lblResult
            // 
            this->lblResult->AutoSize = true;
            this->lblResult->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
            this->lblResult->ForeColor = System::Drawing::Color::DarkGreen;
            this->lblResult->Location = System::Drawing::Point(157, 361);
            this->lblResult->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblResult->Name = L"lblResult";
            this->lblResult->Size = System::Drawing::Size(0, 41);
            this->lblResult->TabIndex = 2;
            this->lblResult->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // labelTitle
            // 
            this->labelTitle->AutoSize = true;
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold));
            this->labelTitle->Location = System::Drawing::Point(150, 38);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = System::Drawing::Size(715, 81);
            this->labelTitle->TabIndex = 3;
            this->labelTitle->Text = L"Number Guessing Game";
            // 
            // labelInstruction
            // 
            this->labelInstruction->AutoSize = true;
            this->labelInstruction->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
            this->labelInstruction->Location = System::Drawing::Point(290, 155);
            this->labelInstruction->Name = L"labelInstruction";
            this->labelInstruction->Size = System::Drawing::Size(514, 37);
            this->labelInstruction->TabIndex = 4;
            this->labelInstruction->Text = L"Can you guess the secret number (1-100)\?";
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::WhiteSmoke;
            this->ClientSize = System::Drawing::Size(1144, 472);
            this->Controls->Add(this->labelInstruction);
            this->Controls->Add(this->labelTitle);
            this->Controls->Add(this->lblResult);
            this->Controls->Add(this->btnGuess);
            this->Controls->Add(this->txtGuess);
            this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->Name = L"MyForm";
            this->Text = L"Number Guessing Game";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        void InitializeGame() {
            // Generate a random number between 1 and 100
            Random^ rand = gcnew Random();
            secretNumber = rand->Next(1, 101);
        }

    private:
        System::Void btnGuess_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                int userGuess = Int32::Parse(txtGuess->Text);

                if (userGuess == secretNumber) {
                    lblResult->ForeColor = System::Drawing::Color::DarkGreen;
                    lblResult->Text = "Congratulations! You guessed the number.";
                }
                else if (userGuess < secretNumber) {
                    lblResult->ForeColor = System::Drawing::Color::Red;
                    lblResult->Text = "Try a higher number.";
                }
                else {
                    lblResult->ForeColor = System::Drawing::Color::Red;
                    lblResult->Text = "Try a lower number.";
                }
            }
            catch (FormatException^) {
                lblResult->ForeColor = System::Drawing::Color::Red;
                lblResult->Text = "Please enter a valid number.";
            }
            catch (OverflowException^) {
                lblResult->ForeColor = System::Drawing::Color::Red;
                lblResult->Text = "Number is too large or too small.";
            }
        }
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
