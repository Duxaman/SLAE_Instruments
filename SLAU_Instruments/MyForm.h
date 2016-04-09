#pragma once
#include "matrix.h"
#include "slae.h"
#include <cmath>
namespace SLAU_Instruments
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::DataGridView^  SourceSLAUunknown;
		protected:
		private: System::Windows::Forms::DataGridView^  SourceSLAUfreemembers;
		private: System::Windows::Forms::DataGridView^  Result;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::NumericUpDown^  sizeNumerator;

		private: System::Windows::Forms::Label^  label4;

		private: System::Windows::Forms::Label^  label6;
		private: System::Windows::Forms::Button^  executeKramerButton;
		private: System::Windows::Forms::Button^  ExecuteReverseButton;
		private: System::Windows::Forms::Button^  ExecuteGaussButton;
		private: System::Windows::Forms::Button^  ExecuteHolecButton;
		private: System::Windows::Forms::Button^  ExecuteIterationButton;
		private: System::Windows::Forms::Button^  ExecuteZedelButton;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::CheckBox^  AutoFillMarker;
		private: System::Windows::Forms::Label^  label5;
		private: System::Windows::Forms::NumericUpDown^  AccuracyMarker;
		private: System::Windows::Forms::Button^  button2;



		private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SourceSLAUunknown = (gcnew System::Windows::Forms::DataGridView());
			this->SourceSLAUfreemembers = (gcnew System::Windows::Forms::DataGridView());
			this->Result = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->sizeNumerator = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->executeKramerButton = (gcnew System::Windows::Forms::Button());
			this->ExecuteReverseButton = (gcnew System::Windows::Forms::Button());
			this->ExecuteGaussButton = (gcnew System::Windows::Forms::Button());
			this->ExecuteHolecButton = (gcnew System::Windows::Forms::Button());
			this->ExecuteIterationButton = (gcnew System::Windows::Forms::Button());
			this->ExecuteZedelButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->AutoFillMarker = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->AccuracyMarker = (gcnew System::Windows::Forms::NumericUpDown());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceSLAUunknown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceSLAUfreemembers))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Result))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeNumerator))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccuracyMarker))->BeginInit();
			this->SuspendLayout();
			// 
			// SourceSLAUunknown
			// 
			this->SourceSLAUunknown->AllowUserToAddRows = false;
			this->SourceSLAUunknown->AllowUserToDeleteRows = false;
			this->SourceSLAUunknown->AllowUserToResizeColumns = false;
			this->SourceSLAUunknown->AllowUserToResizeRows = false;
			this->SourceSLAUunknown->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->SourceSLAUunknown->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SourceSLAUunknown->ColumnHeadersVisible = false;
			this->SourceSLAUunknown->Location = System::Drawing::Point(92, 42);
			this->SourceSLAUunknown->Name = L"SourceSLAUunknown";
			this->SourceSLAUunknown->RowHeadersVisible = false;
			this->SourceSLAUunknown->Size = System::Drawing::Size(479, 580);
			this->SourceSLAUunknown->TabIndex = 0;
			// 
			// SourceSLAUfreemembers
			// 
			this->SourceSLAUfreemembers->AllowUserToAddRows = false;
			this->SourceSLAUfreemembers->AllowUserToDeleteRows = false;
			this->SourceSLAUfreemembers->AllowUserToResizeColumns = false;
			this->SourceSLAUfreemembers->AllowUserToResizeRows = false;
			this->SourceSLAUfreemembers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SourceSLAUfreemembers->ColumnHeadersVisible = false;
			this->SourceSLAUfreemembers->Location = System::Drawing::Point(615, 42);
			this->SourceSLAUfreemembers->Name = L"SourceSLAUfreemembers";
			this->SourceSLAUfreemembers->RowHeadersVisible = false;
			this->SourceSLAUfreemembers->Size = System::Drawing::Size(118, 580);
			this->SourceSLAUfreemembers->TabIndex = 1;
			// 
			// Result
			// 
			this->Result->AllowUserToAddRows = false;
			this->Result->AllowUserToDeleteRows = false;
			this->Result->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->Result->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Result->Location = System::Drawing::Point(92, 664);
			this->Result->Name = L"Result";
			this->Result->ReadOnly = true;
			this->Result->Size = System::Drawing::Size(641, 62);
			this->Result->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(615, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Свободные члены";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(92, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Неизвестные члены";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(769, 42);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(380, 26);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Выберете размерность матрицы СЛАУ и введите необходимую систему \r\nв полях слева, "
				L" не забудьте указать точность.\r\n";
				// 
				// sizeNumerator
				// 
			this->sizeNumerator->Location = System::Drawing::Point(983, 112);
			this->sizeNumerator->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->sizeNumerator->Name = L"sizeNumerator";
			this->sizeNumerator->Size = System::Drawing::Size(120, 20);
			this->sizeNumerator->TabIndex = 6;
			this->sizeNumerator->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(772, 112);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(132, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Количество переменных";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(92, 645);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(125, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Корни данной системы";
			// 
			// executeKramerButton
			// 
			this->executeKramerButton->Location = System::Drawing::Point(805, 278);
			this->executeKramerButton->Name = L"executeKramerButton";
			this->executeKramerButton->Size = System::Drawing::Size(266, 23);
			this->executeKramerButton->TabIndex = 10;
			this->executeKramerButton->Text = L"Решить используя метод Крамера";
			this->executeKramerButton->UseVisualStyleBackColor = true;
			this->executeKramerButton->Click += gcnew System::EventHandler(this, &MyForm::executeKramerButton_Click);
			// 
			// ExecuteReverseButton
			// 
			this->ExecuteReverseButton->Location = System::Drawing::Point(805, 307);
			this->ExecuteReverseButton->Name = L"ExecuteReverseButton";
			this->ExecuteReverseButton->Size = System::Drawing::Size(266, 23);
			this->ExecuteReverseButton->TabIndex = 11;
			this->ExecuteReverseButton->Text = L"Решить используя метод Обратной матрицы";
			this->ExecuteReverseButton->UseVisualStyleBackColor = true;
			this->ExecuteReverseButton->Click += gcnew System::EventHandler(this, &MyForm::ExecuteReverseButton_Click);
			// 
			// ExecuteGaussButton
			// 
			this->ExecuteGaussButton->Location = System::Drawing::Point(805, 336);
			this->ExecuteGaussButton->Name = L"ExecuteGaussButton";
			this->ExecuteGaussButton->Size = System::Drawing::Size(266, 23);
			this->ExecuteGaussButton->TabIndex = 12;
			this->ExecuteGaussButton->Text = L"Решить используя схему Гаусса";
			this->ExecuteGaussButton->UseVisualStyleBackColor = true;
			this->ExecuteGaussButton->Click += gcnew System::EventHandler(this, &MyForm::ExecuteGaussButton_Click);
			// 
			// ExecuteHolecButton
			// 
			this->ExecuteHolecButton->Location = System::Drawing::Point(805, 365);
			this->ExecuteHolecButton->Name = L"ExecuteHolecButton";
			this->ExecuteHolecButton->Size = System::Drawing::Size(266, 23);
			this->ExecuteHolecButton->TabIndex = 13;
			this->ExecuteHolecButton->Text = L"Решить используя схему Холецкого";
			this->ExecuteHolecButton->UseVisualStyleBackColor = true;
			this->ExecuteHolecButton->Click += gcnew System::EventHandler(this, &MyForm::ExecuteHolecButton_Click);
			// 
			// ExecuteIterationButton
			// 
			this->ExecuteIterationButton->Location = System::Drawing::Point(805, 394);
			this->ExecuteIterationButton->Name = L"ExecuteIterationButton";
			this->ExecuteIterationButton->Size = System::Drawing::Size(266, 23);
			this->ExecuteIterationButton->TabIndex = 14;
			this->ExecuteIterationButton->Text = L"Решить используя метод простых итераций";
			this->ExecuteIterationButton->UseVisualStyleBackColor = true;
			this->ExecuteIterationButton->Click += gcnew System::EventHandler(this, &MyForm::ExecuteIterationButton_Click);
			// 
			// ExecuteZedelButton
			// 
			this->ExecuteZedelButton->Location = System::Drawing::Point(805, 423);
			this->ExecuteZedelButton->Name = L"ExecuteZedelButton";
			this->ExecuteZedelButton->Size = System::Drawing::Size(266, 23);
			this->ExecuteZedelButton->TabIndex = 15;
			this->ExecuteZedelButton->Text = L"Решить используя метод Зейделя";
			this->ExecuteZedelButton->UseVisualStyleBackColor = true;
			this->ExecuteZedelButton->Click += gcnew System::EventHandler(this, &MyForm::ExecuteZedelButton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(983, 188);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Создать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::InitSLAU);
			// 
			// AutoFillMarker
			// 
			this->AutoFillMarker->AutoSize = true;
			this->AutoFillMarker->Location = System::Drawing::Point(792, 194);
			this->AutoFillMarker->Name = L"AutoFillMarker";
			this->AutoFillMarker->Size = System::Drawing::Size(160, 17);
			this->AutoFillMarker->TabIndex = 17;
			this->AutoFillMarker->Text = L"Автоматически заполнить";
			this->AutoFillMarker->UseVisualStyleBackColor = true;
			this->AutoFillMarker->CheckedChanged += gcnew System::EventHandler(this, &MyForm::setRandomMarker);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(772, 146);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(185, 26);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Точность \r\n(Количество знаков поле запятой):";
			// 
			// AccuracyMarker
			// 
			this->AccuracyMarker->Location = System::Drawing::Point(983, 152);
			this->AccuracyMarker->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->AccuracyMarker->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->AccuracyMarker->Name = L"AccuracyMarker";
			this->AccuracyMarker->Size = System::Drawing::Size(120, 20);
			this->AccuracyMarker->TabIndex = 19;
			this->AccuracyMarker->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(983, 230);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Сбросить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::clear);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1152, 747);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->AccuracyMarker);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->AutoFillMarker);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ExecuteZedelButton);
			this->Controls->Add(this->ExecuteIterationButton);
			this->Controls->Add(this->ExecuteHolecButton);
			this->Controls->Add(this->ExecuteGaussButton);
			this->Controls->Add(this->ExecuteReverseButton);
			this->Controls->Add(this->executeKramerButton);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->sizeNumerator);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Result);
			this->Controls->Add(this->SourceSLAUfreemembers);
			this->Controls->Add(this->SourceSLAUunknown);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Инструменты по решению СЛАУ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceSLAUunknown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceSLAUfreemembers))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Result))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sizeNumerator))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AccuracyMarker))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: bool _randomState;
		/*Инициализация формы для ввода СЛАУ*/
		private: System::Void InitSLAU(System::Object^  sender, System::EventArgs^  e)
		{
			int size = System::Convert::ToInt32(sizeNumerator->Value);
			SourceSLAUunknown->RowCount = size;
			SourceSLAUunknown->ColumnCount = size;
			SourceSLAUfreemembers->RowCount = size;
			SourceSLAUfreemembers->ColumnCount = 1;
			if (_randomState)
			{
				Random ^ Randomizer = gcnew Random();
				for (int i = 0; i < size; ++i)
					for (int j = 0; j < size; ++j)
					{
						SourceSLAUunknown->Rows[i]->Cells[j]->Value = Randomizer->Next(20);
					}
				for (int i = 0; i < size; ++i)
				{
					SourceSLAUfreemembers->Rows[i]->Cells[0]->Value = Randomizer->Next(20);
				}
			}
		}
		/*Заполнение итоговой матрицы*/
		private: void fillResultGrid(Matrix Results)
		{
			int size = Results.getColsCount();
			int accuracy = System::Convert::ToInt32(AccuracyMarker->Value);
			Result->ColumnCount = size;
			Result->RowCount = 1;
			for (int i = 0; i < Results.getColsCount(); ++i)
			{
				Result->Rows[0]->Cells[i]->Value = System::Math::Round(Results.getElement(0, i), accuracy, MidpointRounding::ToEven);
			}
		}
		/*Установка маркера рандомного ввода*/
		private: void setRandomMarker(System::Object^  sender, System::EventArgs^  e)
		{
			_randomState = System::Convert::ToBoolean(AutoFillMarker->CheckState);
		}
		/*Выполнение поиска решений*/
		private: void execute(DataGridView ^ UnknownGrid, DataGridView  ^ FreeGrid, int function)
		{
			int size = UnknownGrid->RowCount;
			if (size >= 2)
			{
				Matrix UnknownMatrix(size, size);
				Matrix FreeMatrix(size, 1);
				try
				{
					for (int i = 0; i < size; ++i)
						for (int j = 0; j < size; ++j)
						{
							UnknownMatrix.setElement(i, j, System::Convert::ToDouble(UnknownGrid->Rows[i]->Cells[j]->Value));
						}
					for (int i = 0; i < size; ++i)
					{
						FreeMatrix.setElement(i, 0, System::Convert::ToDouble(FreeGrid->Rows[i]->Cells[0]->Value));
					}
				}
				catch (System::FormatException^ error)
				{
					MessageBox::Show(error->Message, "Ошибка");
				}
				catch (System::OverflowException^ error)
				{
					MessageBox::Show(error->Message, "Ошибка");
				}
				catch (System::InvalidCastException^ error)
				{
					MessageBox::Show(error->Message, "Ошибка");
				}
				if (UnknownMatrix.det() != 0)
				{
					double Accuracy = pow(10, -System::Convert::ToDouble(AccuracyMarker->Value));
					Matrix Result(1, size);
					switch (function)
					{
						case 0:
						{
							Result = SLAE::solveByKramer(UnknownMatrix, FreeMatrix);
							fillResultGrid(Result);
							break;
						}
						case 1:
						{
							Result = SLAE::solveByReverse(UnknownMatrix, FreeMatrix);
							fillResultGrid(Result);
							break;
						}
						case 2:
						{
							Result = SLAE::solveByGauss(UnknownMatrix, FreeMatrix);
							fillResultGrid(Result);
							break;
						}
						case 3:
						{
							if (UnknownMatrix.checkMainMinors())
							{
								Result = SLAE::solveByHolec(UnknownMatrix, FreeMatrix);
								fillResultGrid(Result);
							} else MessageBox::Show("СЛАУ не может быть решена этим методом", "Ошибка");
							break;
						}
						default:
						{
							if (UnknownMatrix.hasDiagonalPrepotency())
							{
								if (function == 4) Result = SLAE::solveByIteration(UnknownMatrix, FreeMatrix, Accuracy);
								if (function == 5) Result = SLAE::solveByZedel(UnknownMatrix, FreeMatrix, Accuracy);
								fillResultGrid(Result);
							}
							else MessageBox::Show("Введенная матрица не имеет диагонального преобладания", "Ошибка");
						}
					}

				}
				else MessageBox::Show("У заданной системы нет решения", "Ошибка");
			}
			else MessageBox::Show("Данные не заданы", "Ошибка");
		}
		private: System::Void executeKramerButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			execute(SourceSLAUunknown, SourceSLAUfreemembers, 0);
		}
		private: System::Void ExecuteReverseButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			execute(SourceSLAUunknown, SourceSLAUfreemembers, 1);
		}
		private: System::Void ExecuteGaussButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			execute(SourceSLAUunknown, SourceSLAUfreemembers, 2);
		}
		private: System::Void ExecuteHolecButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			execute(SourceSLAUunknown, SourceSLAUfreemembers, 3);
		}
		private: System::Void ExecuteIterationButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			execute(SourceSLAUunknown, SourceSLAUfreemembers, 4);
		}
		private: System::Void ExecuteZedelButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			execute(SourceSLAUunknown, SourceSLAUfreemembers, 5);
		}

		private: System::Void clear(System::Object^  sender, System::EventArgs^  e)
		{
			SourceSLAUunknown->RowCount = 0;
			SourceSLAUunknown->ColumnCount = 0;
			SourceSLAUfreemembers->RowCount = 0;
			SourceSLAUfreemembers->ColumnCount = 0;
			Result->ColumnCount = 0;
		}
	};
}
