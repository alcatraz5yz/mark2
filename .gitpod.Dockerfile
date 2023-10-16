FROM gitpod/workspace-full

# Install necessary packages
RUN sudo apt-get update && \
    sudo apt-get install -y wget xz-utils

# Download and extract Qt
RUN wget -c https://download.qt.io/official_releases/qt/6.6/6.6.0/single/qt-everywhere-src-6.6.0.tar.xz && \
    tar -xf qt-everywhere-src-6.6.0.tar.xz
