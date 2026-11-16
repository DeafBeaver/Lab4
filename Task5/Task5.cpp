#include "pch.h"
#include <cmath>


using namespace System;

int main(array<System::String ^> ^args)
{
	Console::OutputEncoding = System::Text::Encoding::UTF8;
	Console::InputEncoding = System::Text::Encoding::UTF8;
	double R;
	double R2;
	Console::WriteLine(L"Введіть радіус: \nВід: ");
	R = Convert::ToDouble(Console::ReadLine());
	Console::WriteLine(L"До: ");
	R2 = Convert::ToDouble(Console::ReadLine());
	if (R2 < R) {
		double temp = R;
		R = R2;
		R2 = temp;
	}
	double n = 0.0018;
	double dP = 0.02;
	double l = 2;

	array<double>^ V = gcnew array<double>((int)(R2 - R + 1));

	for(int i = 0; i < V->Length; i++)
	{
		double currentR = R + i;
		V[i] = (3.14159 * pow(currentR, 4)) / (double)(8 * n * l) * dP;
	}
	Console::WriteLine(L"V =\t");
	for(int i = 0; i < V->Length; i++)
	{
		double currentR = R + i;
		Console::WriteLine(L"\tV[{0}] = {1:0.0000}", currentR, V[i]);
	}


	Console::WriteLine(L"\nВведіть розмір матриць: ");
	int size = Convert::ToInt32(Console::ReadLine());
	array<int, 2>^ first= gcnew array<int, 2>(size, size);
	array <int, 2>^ second = gcnew array<int, 2>(size, size);
	array <int, 2>^ newArr = gcnew array<int, 2>(size, size);

	Random^ rand = gcnew Random();

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			first[i, j] = rand->Next(-10, 10);
			second[i, j] = rand->Next(-10, 10);
		}
	}
	Console::WriteLine(L"Перша матриця: ");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			Console::Write(first[i, j] + "\t");
		}
		Console::WriteLine();
	}
	Console::WriteLine(L"Друга матриця: ");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			Console::Write(second[i, j] + "\t");
		}
		Console::WriteLine();
	}
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			newArr[i, j] = first[i, j] * second[i, j];
		}
	}
	Console::WriteLine(L"Нова матриця: ");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			Console::Write(newArr[i, j] + "\t");
		}
		Console::WriteLine();
	}
	return 0;
}
