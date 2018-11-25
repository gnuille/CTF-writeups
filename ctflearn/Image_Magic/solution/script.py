from PIL import Image
im = Image.open("im.jpg")
newim = Image.new(im.mode, (int(im.size[0]/304), 304))

listim = list(im.getdata())
newim.putdata(listim)
newim.save("out.jpg")

