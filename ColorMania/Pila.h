#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Pila
{
private:
    System::Collections::Generic::Stack<String^>^ pila; // Utilizamos la clase Stack de System::Collections::Generic para la pila
    List<String^>^ elementos;

public:
    Pila(int capacidad)
    {
        // Inicializar la pila con la capacidad proporcionada
        pila = gcnew System::Collections::Generic::Stack<String^>(capacidad);
        elementos = gcnew List<String^>();
    }

    bool EstaVacia() {
        return elementos->Count == 0;
    }

    void Push(String^ valor)
    {
        pila->Push(valor);
    }

    String^ Pop()
    {
        if (!IsEmpty())
            return pila->Pop();
        return nullptr; // Manejo de error si la pila est� vac�a
    }

    bool IsEmpty()
    {
        return pila->Count == 0;
    }
    // M�todo para contar los elementos en la pila
    int Contar() {
        return elementos->Count;
    }

    // M�todo para obtener el elemento en la posici�n especificada
    String^ Obtener(int posicion) {
        if (posicion >= 0 && posicion < elementos->Count) {
            return elementos[posicion];
        }
        else {
            return nullptr; // Opcional: puedes lanzar una excepci�n en lugar de devolver nullptr si lo prefieres
        }
    }
};
