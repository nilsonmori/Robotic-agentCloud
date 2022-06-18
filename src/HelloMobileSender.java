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

public class HelloMobileSender implements NodeConnectionListener {

  private static String       gatewayIP    = "10.0.10.174";
  private static int          gatewayPort  = 5500;
  private MrUdpNodeConnection connection;
  private UUID                myUUID;

  public HelloMobileSender() {
    myUUID = UUID.fromString("bb103877-8335-444a-be5f-db8d916f6754");
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
    Logger.getLogger("").setLevel(Level.ALL);

    if (args.length == 3) {
      gatewayIP = args[0];
      gatewayPort = Integer.parseInt(args[1]);
      HelloMobileSender sender = new HelloMobileSender();
      sender.sendMessage(args[2]);
    } else {
      System.err.println("Quantidade de parametros deve ser igual a 3: [IP] [PORTA] [MSG]");
    }

  }
  
  public void sendMessage(String msg) {
      ApplicationMessage message = new ApplicationMessage();
      message.setContentObject(msg);
      message.setRecipientID(UUID.fromString("788b2b22-baa6-4c61-b1bb-01cff1f5f878"));

      try {
        connection.sendMessage(message);
      } catch (IOException e) {
        e.printStackTrace();
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
    System.out.println("Confirmação: " + message.getContentObject());
  }

  public void reconnected(NodeConnection remoteCon, SocketAddress endPoint, boolean wasHandover, boolean wasMandatory) {}

  public void disconnected(NodeConnection remoteCon) {}

  public void unsentMessages(NodeConnection remoteCon, List<Message> unsentMessages) {}

  public void internalException(NodeConnection remoteCon, Exception e) {}
}