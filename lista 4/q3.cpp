#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Cliente {
private:
    std::string nome;
    std::string cpf;
    double limite;
    Cliente* socio;

public:
    Cliente(std::string nome, std::string cpf, double limite) 
        : nome(nome), cpf(cpf), limite(limite), socio(nullptr) {
        if (nome.empty()) throw std::invalid_argument("Nome invalido");
        if (cpf.empty()) throw std::invalid_argument("CPF invalido");
        if (limite < 0) throw std::invalid_argument("Limite invalido");
    }

    void set_socio(Cliente* c) {
        socio = c;
        c->socio = this;
    }

    double get_limite() const {
        return (socio == nullptr) ? limite : limite + socio->limite;
    }

    std::string to_string() const {
        std::string s = nome + " - " + cpf + " - Limite individual = " + std::to_string(limite) + 
                        " - Limite total = " + std::to_string(get_limite());
        if (socio != nullptr) {
            s += " - Socio = " + socio->nome;
        }
        return s;
    }
};

class Empresa {
private:
    std::string nome;
    std::vector<Cliente*> clientes;

public:
    Empresa(std::string nome) : nome(nome) {
        if (nome.empty()) throw std::invalid_argument("Nome invalido");
    }

    void inserir(Cliente* c) {
        clientes.push_back(c);
    }

    std::vector<Cliente*> listar() const {
        return clientes;
    }

    std::string to_string() const {
        return "Empresa " + nome + " tem " + std::to_string(clientes.size()) + " cliente(s)";
    }
};

class UI {
private:
    static Empresa* empresa;

public:
    static int menu() {
        std::cout << "1 - Nova empresa, 2 - Mostrar empresa, 3 - Inserir cliente, 4 - Listar clientes, 5 - Sociedade, 9 - Fim\n";
        int opcao;
        std::cout << "Informe uma opcao: ";
        std::cin >> opcao;
        return opcao;
    }

    static void nova_empresa() {
        std::cout << "Informe o nome da empresa: ";
        std::string nome;
        std::cin.ignore();
        std::getline(std::cin, nome);
        empresa = new Empresa(nome);
    }

    static void mostrar_empresa() {
        if (empresa != nullptr)
            std::cout << empresa->to_string() << std::endl;
    }

    static void inserir_cliente() {
        std::cout << "Informe o nome: ";
        std::string nome;
        std::cin.ignore();
        std::getline(std::cin, nome);

        std::cout << "Informe o CPF: ";
        std::string cpf;
        std::getline(std::cin, cpf);

        std::cout << "Informe o limite: ";
        double limite;
        std::cin >> limite;

        Cliente* cliente = new Cliente(nome, cpf, limite);
        empresa->inserir(cliente);
    }

    static void listar_clientes() {
        if (empresa != nullptr) {
            for (auto cliente : empresa->listar()) {
                std::cout << cliente->to_string() << std::endl;
            }
        }
    }

    static void sociedade() {
        if (empresa != nullptr) {
            auto clientes = empresa->listar();
            std::cout << "Lista de clientes:\n";
            for (size_t i = 0; i < clientes.size(); ++i) {
                std::cout << i << ": " << clientes[i]->to_string() << std::endl;
            }

            int x, y;
            std::cout << "Informe o numero do 1 cliente: ";
            std::cin >> x;
            std::cout << "Informe o numero do 2 cliente: ";
            std::cin >> y;

            if (x < clientes.size() && y < clientes.size()) {
                clientes[x]->set_socio(clientes[y]);
            }
        }
    }

    static void main() {
        int op = 0;
        while (op != 9) {
            op = menu();
            switch(op){
                case 1:
                    nova_empresa(); 
                    break;
                case 2:
                    mostrar_empresa();
                    break;
                case 3:
                    inserir_cliente();
                    break;
                case 4:
                    listar_clientes();
                    break;
                case 5:
                    sociedade();
                    break;
            }
           
        }
    }
};


Empresa* UI::empresa = nullptr;

int main() {
    UI::main();
    return 0;
}
