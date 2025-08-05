
package br.com.novatec.SistemaVendasApp;

import br.com.novatec.SistemaVendas.Entities.Saida;
import br.com.novatec.SistemaVendas.Entities.Venda;
import javax.swing.table.DefaultTableModel;
import org.springframework.http.ResponseEntity;
import org.springframework.web.client.RestTemplate;

public class VerVendas extends javax.swing.JFrame {

        private final String WS_URL = "http://localhost:8080/venda";     
        private final String WS_URL2 = "http://localhost:8080/saida";  
        private double somador;
        private double somadorsaida;
        
    public VerVendas() {
        initComponents();
    }
    
    private void loadTableData(){
        
        RestTemplate restTemplate = new RestTemplate();
        //representação resposta
        ResponseEntity<Venda[]> response = restTemplate.getForEntity(WS_URL, Venda[].class);
        //resposta obtida    
        Venda[] vendas = response.getBody();
        //conversão para o tipo Default
        DefaultTableModel tableModel = (DefaultTableModel) tbTabela2.getModel();
        
        
        //percorre o array
        for(Venda venda : vendas){
            //criação novo array de objetos 
            Object[] row = { venda.getQuantidade(), venda.getProduto(),venda.getValor(),venda.getVendedor(),venda.getFormaPagamento()};
            somador += venda.getValor();
            tableModel.addRow(row);
        }
        
        RestTemplate restTemplate2 = new RestTemplate();
        
        ResponseEntity<Saida[]> response2 = restTemplate2.getForEntity(WS_URL2, Saida[].class);
        
        Saida[] saidas = response2.getBody();
        
      //  DefaultTableModel tableModel2 = (DefaultTableModel) tbTabela2.getModel();
        
        
        
        for(Saida saida : saidas){
            Object[] row = { "-",saida.getDescricao(), "-"+ saida.getValorSaida(),"-","-"};
            somadorsaida += saida.getValorSaida();
            tableModel.addRow(row);
        }
        
        
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        btnAtualizar = new javax.swing.JToggleButton();
        tbTabela = new javax.swing.JScrollPane();
        tbTabela2 = new javax.swing.JTable();
        tfsubVendas = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        tfSubSaidas = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("TRANSAÇÕES");
        setMaximumSize(new java.awt.Dimension(800, 600));
        setPreferredSize(new java.awt.Dimension(800, 600));

        jPanel1.setBackground(new java.awt.Color(51, 51, 51));
        jPanel1.setForeground(new java.awt.Color(204, 204, 204));
        jPanel1.setMaximumSize(new java.awt.Dimension(600, 600));
        jPanel1.setPreferredSize(new java.awt.Dimension(600, 600));

        btnAtualizar.setBackground(new java.awt.Color(51, 51, 51));
        btnAtualizar.setFont(new java.awt.Font("Castellar", 1, 12)); // NOI18N
        btnAtualizar.setForeground(new java.awt.Color(204, 204, 204));
        btnAtualizar.setText("Atualizar");
        btnAtualizar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAtualizarActionPerformed(evt);
            }
        });

        tbTabela.setBackground(new java.awt.Color(51, 51, 51));
        tbTabela.setForeground(new java.awt.Color(204, 204, 204));

        tbTabela2.setBackground(new java.awt.Color(51, 51, 51));
        tbTabela2.setFont(new java.awt.Font("Castellar", 1, 12)); // NOI18N
        tbTabela2.setForeground(new java.awt.Color(204, 204, 204));
        tbTabela2.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "QUANTIDADE", "DESCRIÇÃO", "VALOR", "VENDEDOR", "PAGAMENTO"
            }
        ));
        tbTabela2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tbTabela2MouseClicked(evt);
            }
        });
        tbTabela.setViewportView(tbTabela2);

        tfsubVendas.setBackground(new java.awt.Color(51, 51, 51));
        tfsubVendas.setFont(new java.awt.Font("Castellar", 1, 12)); // NOI18N
        tfsubVendas.setForeground(new java.awt.Color(204, 204, 204));
        tfsubVendas.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        tfsubVendas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfsubVendasActionPerformed(evt);
            }
        });

        jLabel1.setBackground(new java.awt.Color(204, 204, 204));
        jLabel1.setFont(new java.awt.Font("Castellar", 1, 12)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(204, 204, 204));
        jLabel1.setText("Subtotal Vendas :");

        tfSubSaidas.setBackground(new java.awt.Color(51, 51, 51));
        tfSubSaidas.setFont(new java.awt.Font("Castellar", 1, 12)); // NOI18N
        tfSubSaidas.setForeground(new java.awt.Color(204, 204, 204));
        tfSubSaidas.setHorizontalAlignment(javax.swing.JTextField.RIGHT);
        tfSubSaidas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfSubSaidasActionPerformed(evt);
            }
        });

        jLabel2.setBackground(new java.awt.Color(204, 204, 204));
        jLabel2.setFont(new java.awt.Font("Castellar", 1, 12)); // NOI18N
        jLabel2.setForeground(new java.awt.Color(204, 204, 204));
        jLabel2.setText("Subtotal Saidas :");

        jLabel3.setBackground(new java.awt.Color(204, 204, 204));
        jLabel3.setFont(new java.awt.Font("Castellar", 1, 12)); // NOI18N
        jLabel3.setForeground(new java.awt.Color(204, 204, 204));
        jLabel3.setText("______________________________________________________________________________________________________________________________________________");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 141, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(tfsubVendas, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(tfSubSaidas, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 283, Short.MAX_VALUE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnAtualizar)))
                .addContainerGap())
            .addComponent(tbTabela)
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(btnAtualizar))
                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(tbTabela, javax.swing.GroupLayout.PREFERRED_SIZE, 470, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 15, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tfsubVendas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2)
                    .addComponent(tfSubSaidas, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(6, 6, 6))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, 800, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, 568, javax.swing.GroupLayout.PREFERRED_SIZE)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    
    private void btnAtualizarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAtualizarActionPerformed
        somadorsaida =0;
        somador=0;
    //conversão tabela 
        DefaultTableModel model = (DefaultTableModel) tbTabela2.getModel();
        //obtém o num de linhas
        int rowCount = model.getRowCount();
        //remocão linhas
        for (int i = rowCount - 1; i >= 0; i--) {
        model.removeRow(i);
        }
        //carrega os dados atualizados novamente
        loadTableData();
        //evitar duplicatas
       String somadorFormatado = String.format("%.2f", somador);
       tfsubVendas.setText(somadorFormatado);
       
       String somadorSaidaFormatado = String.format("%.2f", somadorsaida);
       tfSubSaidas.setText(somadorSaidaFormatado);
       
    }//GEN-LAST:event_btnAtualizarActionPerformed

    private void tfSubSaidasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfSubSaidasActionPerformed

    }//GEN-LAST:event_tfSubSaidasActionPerformed

    private void tfsubVendasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfsubVendasActionPerformed
   
    }//GEN-LAST:event_tfsubVendasActionPerformed

    private void tbTabela2MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tbTabela2MouseClicked

    }//GEN-LAST:event_tbTabela2MouseClicked

    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(VerVendas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(VerVendas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(VerVendas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(VerVendas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VerVendas().setVisible(true);
               
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToggleButton btnAtualizar;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane tbTabela;
    private javax.swing.JTable tbTabela2;
    private javax.swing.JTextField tfSubSaidas;
    private javax.swing.JTextField tfsubVendas;
    // End of variables declaration//GEN-END:variables
}
