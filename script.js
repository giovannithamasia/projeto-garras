// Endereço IP da ESP32
const enderecoESP32 = "http://192.168.4.1";

// Elementos da interface
const statusConexao = document.getElementById("statusConexao");
const mensagem = document.getElementById("mensagem");

// Função para enviar comandos
function enviarComando(rota) {

    // Atualiza a mensagem na tela
    mensagem.textContent = "Enviando comando...";

    fetch(enderecoESP32 + rota)

        .then(resposta => {

            if (!resposta.ok) {
                throw new Error("Erro ao enviar comando");
            }

            return resposta.text();
        })

        .then(dados => {

            mensagem.textContent = "Comando executado com sucesso!";

            statusConexao.textContent = "Conectado";

            statusConexao.style.color = "#10b981";

            console.log("Resposta da ESP32:", dados);
        })

        .catch(erro => {

            mensagem.textContent = "Falha na comunicação com a máquina.";

            statusConexao.textContent = "Desconectado";

            statusConexao.style.color = "#f43f5e";

            console.log("Erro na comunicação:", erro);
        });
}
