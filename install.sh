#! /bin/sh

## Configurando o Ambiente
LOCAL=`pwd`
OPENSPLICEGit='/OpenSplice/HDE'
OPENSPLICELOCAL='/opt/OpenSplice'

#Criando diretório no /opt para o OpenSplice
mkdir -p $OPENSPLICELOCAL

# Adicionando Link Simbólico para o local de download do OpenSplice
ln -s $LOCAL$OPENSPLICEGit $OPENSPLICELOCAL'/HDE'  

# Alterando arquivo ospl.xml original para o distribuído pela ContextNet
mv /opt/OpenSplice/HDE/x86_64.linux/etc/config/ospl.xml /opt/OpenSplice/HDE/x86_64.linux/etc/config/ospl.xml.OLD
cp dependences/ospl.xml /opt/OpenSplice/HDE/x86_64.linux/etc/config/ospl.xml

# Copiando variáveis de ambiente
cp dependences/opensplice.sh /etc/profile.d/opensplice.sh

# habilitando serviço
ln -s /opt/Robotic-agentCloud/OpenSplice/contextNet.sh /usr/bin






