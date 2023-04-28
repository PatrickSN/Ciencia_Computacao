//variaveis
function q1(varA, varB) {
    let a = varA;
    let b = varB;
    if (a !== "" && b !== "") {
        console.log(a, b);

        let aux = a;

        a = b;
        b = aux;

        console.log(a, b);
    } else {
        console.log("Insira as variáveis");
    }
};

//if/else/switch/case
function q2(user) { // if/ else eh a msm coisa de C; switch tb, mas eu nn lembrava

    let usuario = user; // comum, gerente, adm
    switch (usuario) {
        case "comum":
            console.log("Usuário Comum!");
            break;

        case "gerente":
            console.log("Usuário Gerente!");
            break;

        case "adm":
            console.log("Usuário Administrador!");
            break;

        default:
            console.log("Usuário não detectado!");
    }
};

//for/while/do while/for in/ for of
function q3() { //for e while eh oq a gente ja sabe

    //do while
    let i = 0;
    do {
        i++;
        console.log("testando " + i);
    } while (i < 3);
    console.log("")

    // for in
    const pessoa = {
        nome: "Lucas",
        idade: 21,
        altura: 171
    }

    for (let chave in pessoa) {

        console.log(chave, pessoa[chave]);
    }

    console.log("")

    const cores = ["vermelho", "azul", "branco", "roza"];

    for (let indice in cores) {

        console.log(indice, cores[indice]);
    }
    console.log("");

    //for of
    for (let cor of cores) {
        console.log(cor);
    }
};

//exercicio nº 2
function q4(varA, varB) {
    function maior(valor1, valor2) {
        if (valor1 > valor2) {
            return valor1;
        } else if (valor2 > valor1) {
            return valor2;
        } else {
            return "Os dois valores são iguais";
        }
    }
    let a = varA
    b = varB
    console.log(maior(a, b));
};

//exercicio nº 3 FizzBuzz= Se a entrada for divisivel por 3, imprime fizz
//se for divisivel por 5, imprime buzz
// se ambas imprime fizzbuzz
function q5(varA) {
    const resultado = console.log(fizzBuzz(varA));

    function fizzBuzz(entrada) {
        if (typeof entrada !== "number") {
            return "Não é um número";
        } else if (entrada % 3 === 0 && entrada % 5 === 0) {
            return "FizzBuzz";
        } else if (entrada % 3 === 0) {
            return "Fizz";
        } else if (entrada % 5 === 0) {
            return "Buzz";
        } else {
            return entrada;
        }
    }
};

//exercicio nº 4 medidor velocidade e 
// velocidade max 70km/h
// a cada 5km/h acima da velocidade conta 1 ponto na carteira
// acima de 12 pontos a carteira eh suspensa
function q6(varA) {
    verificarVelocidade(varA);

    function verificarVelocidade(velocidade) {
        const velMax = 70
        if (velocidade <= velMax) {
            console.log("OK");
        } else {
            let aux = velocidade - velMax;
            const pontos = Math.floor(aux / 5);
            if (pontos < 12) {
                console.log("Pontos: " + pontos);
            } else {
                console.log("Carteira Suspensa");
            }
        }
    }
};

//exercicio nº 5 
//receber uma quantidade de valores para avaliar
//funçao exibe se cada valor eh par ou impar
function q7(varA) {
    exibirTipo(varA);

    function exibirTipo(limite) {
        for (let i = 0; i <= limite; i++) {
            if (i % 2 === 0) {
                console.log(i + "- PAR");
            } else {
                console.log(i + "- IMPAR");
            }
        }
    }
};

//criar um metodo para ler as propriedades de um objeto 
//exibir somente as propriedades do tipo string 
function q8(varA, varB, varC, varD) {
    const filme = {
        titulo: varA,
        ano: varB,
        autor: varC,
        duracao: varD
    };
    exibirPropriedades();

    function exibirPropriedades(Objeto) {
        for (let prop in objeto) {
            if (typeof objeto[prop] === "string") {
                console.log(prop + ": " + objeto[prop]);
            }
        }
    }
};

//criar uma funçao somar q retorna a soma 
//de tds os multiplos de 3 e 5 dento de um limite
function q9(varA) {
    somar(varA);

    function somar(limite) {
        let mult1 = 3;
        let mult2 = 5;
        let somaTotal = 0;


        for (let i = 0; i <= limite; i++) {
            if (i % mult1 === 0 && i % mult2 === 0) {
                somaTotal += i;
            } else if (i % mult1 === 0) {
                somaTotal += i;
            } else if (i % mult2 === 0) {
                somaTotal += i;
            }
        }
        console.log(somaTotal)
    }
}

function q10() {
    let nome = document.getElementById("name").value;
    let email = document.getElementById("email").nodeValue;
    console.log(nome, email);
    alert("Olá " + nome);
}