# 构建流媒体服务

## 0. 配置SRS
- SRS是一个流媒体服务器，可以用来推流和拉流
1. `git clone https://github.com/ossrs/srs.git`
2. `cd srs/trunk`
3. `./configure --osx`：针对osx系统
4. `make`
5. 执行: `./objs/srs -c conf/srs.conf`
   - 查看状态: `./etc/init.d/srs status`
   - 停止运行: `./etc/init.d/srs stop`
   - 启动: `./etc/init.d/srs start`
6. 查看日志: `tail -f ./objs/srs.log`
7. 运行网站: `127.0.0.1:8080`

## 1. 配置RTMP
- RTMP是SRS的流媒体服务，可以用来推流和拉流
1. 运行: `./objs/srs -c conf/rtmp.conf`
2. SRS推流：
   1. `ffmpeg -re -i ./doc/source.200kbps.768x320.flv -c copy -f -y flv rtmp://10.151.124.79/live/livestream`
3. 播放流媒体信息: `ffplay -i rtmp://[]`

## 2. 配置HLS
- HLS是SRS的流媒体服务，可以用来推流和拉流
- HLS是苹果公司推出的基于HTTP的流媒体传输协议，可以实现直播和点播

1. 启动: `./objs/srs -c conf/hls.conf`
2. 推流: `ffmpeg -re -i ./input.mp4 -codec copy -f flv -y rtmp://[]`
3. 播放: `ffplay -i http://[]`

## 3. HTTP-FLV 流媒体服务
1. 配置文件: `http.flv.live.conf`
2. run: `./objs/srs -c conf/http.flv.live.conf`
3. push stream: `ffmpeg -re -i ./input.mp4 -codec copy -f flv -y rtmp://10.151.124.79/live/livestream`
4. play: `ffplay -i http://192.168.0.108:8080/live/livestream.flv`


## Nginx的RTMP流媒体服务
1. 安装Nginx
   - `brew install nginx-full --with-rtmp-module`
2. 配置文件: `nginx.conf`
3. 启动: `nginx`

### Nginx流媒体模块 nginx-rtmp-module
- `nginx-htp-flv-module`：支持HTTP-FLV
- `nginx-rtmp-module`：支持RTMP
- 编译: `git clone https://github.com/arut/nginx-rtmp-module.git`
  - `./configure --add-module=../nginx_output --add-module=../nginx-rtmp-module`
  - `make`
  - `make install`