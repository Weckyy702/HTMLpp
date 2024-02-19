# HTML++: Your favorite library for compile-time HTML in C++

Have you ever wondered what it would look like to abuse the C++ compiler to compile HTML?

Well, here we go.

## Syntax examples

HTML++ currently supports only a few tags:
- ```<html>```
- ```<body>```
- ```<h1>```
- ```<div>```
- ```<ul>```
- ```<li>```
- ```<p>```

A typical page might look something like this:
```cpp
  using html = 
  Document<
    Body<
      H1<"My first heading">,
      P<$(12)>
    >
  >;

```

And the output (after prettier):
```html
<!doctype html>
<html>
  <body>
    <h1>My first heading</h1>
    <p>12</p>
  </body>
</html>
```

## ToDos

- [ ] Attributes
- [ ] Many more tags
