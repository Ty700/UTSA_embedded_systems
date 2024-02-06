FROM python:3.8

RUN apt-get update && \
    apt-get install -y pkg-config build-essential cmake wget git && \
    rm -rf /var/lib/apt/lists/*
COPY . app/
WORKDIR /app

CMD ["python", "./hello.py"]
