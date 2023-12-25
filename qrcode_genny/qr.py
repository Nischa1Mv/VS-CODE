import qrcode

img = qrcode.make("https://github.com/Nischa1Mv")
img.save("qr.png","PNG")