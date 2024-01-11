function numeros(){
    let pos =0
    let neg = 0
    for(let i=0; i<=3;i++){
        let n = parseInt(prompt('Informe um numero'))
        if (n >=0 ){
            pos += 1
      
        }else{
            neg +=1
         
        }

    }
   
}

console.log(`${neg} negativos, ${pos} pos `)