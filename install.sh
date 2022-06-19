#! /bin/sh

echo "Configurando o Ambiente........................................"
LOCAL=`pwd`
OPENSPLICEGit='/OpenSplice/HDE'
OPENSPLICELOCAL='/opt/OpenSplice'

echo "Criando diretório no /opt para o OpenSplice..................."
mkdir -p $OPENSPLICELOCAL

echo "Adicionando Link Simbólico para o OpenSplice................."
ln -s $LOCAL$OPENSPLICEGit $OPENSPLICELOCAL'/HDE'

echo "Alterando arquivo ospl.xml para o distribuído pela ContextNet"
mv /opt/OpenSplice/HDE/x86_64.linux/etc/config/ospl.xml /opt/OpenSplice/HDE/x86_64.linux/etc/config/ospl.xml.OLD
cp dependences/ospl.xml /opt/OpenSplice/HDE/x86_64.linux/etc/config/ospl.xml

echo "Copiando variáveis de ambiente ............................."
cp dependences/opensplice.sh /etc/profile.d/opensplice.sh

echo "Habilitando script de inicialização ......................."
ln -s /opt/Robotic-agentCloud/OpenSplice/contextNet.sh /usr/bin

echo "Reinicie o sistema"

echo ""

echo "após reiniciar execute: contextNet.sh"






