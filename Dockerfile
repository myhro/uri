FROM centos:7

RUN yum install -y centos-release-scl
RUN yum install -y gcc gdb rh-python34

RUN echo "source /opt/rh/rh-python34/enable" >> /root/.bashrc
