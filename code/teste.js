const nomeNave = prompt("Digite o nome da nave:");
let velocidade = 0;    

function menu(){
    return prompt("Escolha uma opção:\n[1] Acelerar a nave em 5km/s\n[2] Desacelerar a nave em 5km/s\n[3] Imprimir dados de bordo\n[4] Sair do programa");
}

function acoes(valorMenu){
    switch(valorMenu){
        case 1:
            velocidade += 5;
            break
        case 2:
            if(velocidade >= 5)
                velocidade -= 5;
            break
        case 3:
            alert(`Nome da nave:${nomeNave}\nVelocidade atual:${velocidade}`);
            break
        default:
            alert("saindo do progama");
            return -1;
    }
    return 0;
}
    
    

while(true){
    
    let valorMenu = parseInt(menu());
    let valorAcoes = acoes(valorMenu);

    if(valorAcoes === -1)
        break
}

