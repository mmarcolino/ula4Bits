#Código principal
def main():
    nome = input("Insira o nome do arquivo de teste: ")
    listaDeComandos = escaneiaArquivo(nome)
    file = open("resultado.hex", "w")
    for i in listaDeComandos:
        file.write(i)
    file.close()
    
#Função responsável por ler o arquvio
def escaneiaArquivo(fileName: str):
    lista = [] #lista que armazena cada um dos valores hex para a ULA
    x: str; y: str; w: str; resultado: str; linha: str
    try: 
        file = open(fileName, "r") #abrindo o arquivo .txt
    except:
        print("Arquivo não encontrado")
    linha = file.readline().strip()
    while linha != "fim.": #loop que avalia cada linha do arquivo
       if linha != "inicio:":
           if linha[0] == 'X':
               x = linha[2]
           elif linha[0] == "Y":
                y = linha[2]
           else:
               w = substituiOperacao(linha[2:linha.rfind(";")]) #chama a função que substitui por hex e armazena em W
               resultado = x + y + w
               lista.append(resultado) #insere o resultado Concatenado na lista
       linha = file.readline().strip()
    file.close()
    return lista

#Função responsável por substituir a operação por um valor hexadecimal
def substituiOperacao(comando: str):
    #dictionary utilizado para atribuir os valores a suas respectivas operações(chave: valor)
    dic = {
        "An" : "0",
        "nAoB": "1",
        "AnB": "2",
        "zeroL": "3",
        "nAeB": "4",
        "Bn" : "5",
        "AxB": "6",
        "ABn": "7",
        "AnoB": "8",
        "nAxB": "9",
        "copiaB": "A",
        "AB": "B",
        "umL": "C",
        "AoBn": "D",
        "AoB": "E",
        "copiaA": "F"
    }
    return dic[comando]#usa o comando passado como parâmetro como chave para retornar o valor desejado

if __name__ == "__main__":
    main()