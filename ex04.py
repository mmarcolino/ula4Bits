from inspect import _void
from opcode import opname

#Código principal
def main():
    fileName = input("Insira o nome do arquivo de teste: ")
    try:
        file = open(fileName, "r")
    except:
        print("Arquivo não encontrado")
    escaneiaArquivo(file)
    
if __name__ == "__main__":
    main()

#Função responsável por ler o arquvio
def escaneiaArquivo(arquivo):
    #inserir comandos de leitura
    return _void