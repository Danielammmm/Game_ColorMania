public ref class Cola
{
private:
    System::Collections::Generic::Queue<System::String^>^ cola;

public:
    Cola()
    {
        cola = gcnew System::Collections::Generic::Queue<System::String^>();
    }

    void Encolar(System::String^ valor)
    {
        cola->Enqueue(valor);
    }

    System::String^ Desencolar()
    {
        if (cola->Count > 0)
            return cola->Dequeue();
        return nullptr; // Manejo de error si la cola está vacía
    }
};
