#pragma once

using namespace System;
using namespace System::Collections::Generic;

generic <typename T>
public ref class Lista
{
private:
    List<T>^ lista; // Utilizamos List de System::Collections::Generic para la lista

public:
    Lista()
    {
        lista = gcnew List<T>();
    }

    void Agregar(T valor)
    {
        lista->Add(valor);
    }

};
