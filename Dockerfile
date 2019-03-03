FROM centos:7

RUN yum install -y centos-release-scl
RUN yum install -y gcc gcc-c++ gdb less rh-python34

RUN echo "source /opt/rh/rh-python34/enable" >> /root/.bashrc
