FROM gitpod/workspace-full

# Install Qt6
RUN sudo apt-get update && \
    sudo apt-get install -y qt6-default
