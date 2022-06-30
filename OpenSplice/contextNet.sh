#! /bin/sh
while true
do
	echo "Iniciando contexNet"
	/usr/bin/java -jar /opt/Robotic-agentCloud/OpenSplice/contextnet-2.7-eSMA.jar 127.0.0.1 5500 OpenSplice &
	pid=$!
	echo $pid
	sleep 28800
	echo "Encerrando contexNet"
	kill $pid
done
