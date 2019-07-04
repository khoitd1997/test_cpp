#This is a sample Image 
FROM fedora:latest 
LABEL maintainer khoidinhtrinh@gmail.com 

RUN dnf install ninja-build gcc-c++ clang cmake -y
RUN dnf install cppcheck python3 -y
RUN pip3 install cpplint
RUN dnf install spdlog libasan libubsan gtest-devel gtest -y
RUN mkdir -p builddir
COPY . builddir
CMD ["/builddir/build.sh"]