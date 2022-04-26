from inspect import _void
from opcode import opname

#Função responsável por ler o arquvio
def escaneiaArquivo(fileName):
    x = 0; y = 0; linha = ""; comando = ""
    try:
        file = open(fileName, "r")
    except:
        print("Arquivo não encontrado")
    linha = file.readline()
    while(linha != ""):
       linha.strip()
       if(linha != "inicio:" or linha != "fim."):
           if(linha[0] == 'x'):
               x = linha[2]
           elif(linha[0] == "y"):
                y = linha[2]
           else:
               comando = linha[2:linha.rfind(";")]
       else:
           break
       linha = file.readline()
    return _void

def substituiComando():
    return _void

#Código principal
nome = input("Insira o nome do arquivo de teste: ")
teste = escaneiaArquivo(nome)