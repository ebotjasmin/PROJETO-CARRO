function combustivel(){


document.getElementById("tela").innerHTML = `

<h2>Medidor de Combustível</h2>


<input id="carro" placeholder="Modelo do carro">


<input id="tanque" placeholder="Capacidade do tanque">


<input id="litros" placeholder="Combustível atual">


<button onclick="mostrarCarro()">
Iniciar
</button>


<p id="resultado"></p>

`;

}



function mostrarCarro(){


let carro =
document.getElementById("carro").value;


let tanque =
document.getElementById("tanque").value;


let litros =
document.getElementById("litros").value;



document.getElementById("resultado").innerHTML =

`
🚗 ${carro}<br><br>

Tanque: ${tanque} L<br>

Combustível:
${litros} L<br><br>

Consumo médio:
12 km/L<br>

Autonomia:
${litros*12} km

`;

}



function poupanca(){


document.getElementById("tela").innerHTML = `


<h2>Poupança</h2>


<input id="valor" placeholder="Valor inicial">


<input id="meses" placeholder="Meses">


<button onclick="calcularPoupanca()">
Calcular
</button>


<p id="resultado"></p>

`;

}



function calcularPoupanca(){


let valor =
Number(document.getElementById("valor").value);


let meses =
Number(document.getElementById("meses").value);



let final = valor;


for(let i=0;i<meses;i++){

final = final * 1.006;

}



document.getElementById("resultado").innerHTML =

`

Valor final:
R$ ${final.toFixed(2)}

<br>

Lucro:
R$ ${(final-valor).toFixed(2)}

`;

}