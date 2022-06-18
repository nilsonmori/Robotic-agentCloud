package main;
import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.util.List;
import java.util.UUID;
import java.util.logging.Level;
import java.util.logging.Logger;

import lac.cnclib.net.NodeConnection;
import lac.cnclib.net.NodeConnectionListener;
import lac.cnclib.net.mrudp.MrUdpNodeConnection;
import lac.cnclib.sddl.message.ApplicationMessage;
import lac.cnclib.sddl.message.Message;

public class HelloMobileReceiver implements NodeConnectionListener {

  private static String       gatewayIP  = "10.0.10.174";
  private static int          gatewayPort  = 5500;
  private MrUdpNodeConnection connection;
  private UUID                myUUID;
  
  public HelloMobileReceiver() {
    myUUID = UUID.fromString("788b2b22-baa6-4c61-b1bb-01cff1f5f878");
    InetSocketAddress address = new InetSocketAddress(gatewayIP, gatewayPort);
    try {
      connection = new MrUdpNodeConnection(myUUID);
      connection.addNodeConnectionListener(this);
      connection.connect(address);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    Logger.getLogger("").setLevel(Level.INFO);

    if (args.length == 2) {
      gatewayIP = args[0];
      gatewayPort = Integer.parseInt(args[1]);
      new HelloMobileReceiver();
    } else {
      System.err.println("Quantidade de parametros deve ser igual a 2: [IP] [PORTA]");
    }
  }

  public void connected(NodeConnection remoteCon) {
    ApplicationMessage message = new ApplicationMessage();
    message.setContentObject("Registering");

    try {
        connection.sendMessage(message);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public void newMessageReceived(NodeConnection remoteCon, Message message) {
    System.out.println("Mensagem Recebida: " + message.getContentObject());
    
    ApplicationMessage appMessage = new ApplicationMessage();
    appMessage.setContentObject("Mensagem de confirmação de recepção no destino!");
    appMessage.setRecipientID(message.getSenderID());
    
    try {
      connection.sendMessage(appMessage);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public void reconnected(NodeConnection remoteCon, SocketAddress endPoint, boolean wasHandover, boolean wasMandatory) {}

  public void disconnected(NodeConnection remoteCon) {}

  public void unsentMessages(NodeConnection remoteCon, List<Message> unsentMessages) {}

  public void internalException(NodeConnection remoteCon, Exception e) {}
}