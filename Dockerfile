FROM centos:7

RUN yum install -y centos-release-scl
RUN yum install -y gcc gcc-c++ gdb rh-python34

RUN echo "source /opt/rh/rh-python34/enable" >> /root/.bashrc

ADD go1.8.1.linux-amd64.tar.gz /usr/local/
RUN ln -s /usr/local/go/bin/go /usr/local/bin/go
