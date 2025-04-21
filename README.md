# RayTracer

## Compilation with Makefile

The project uses a `Makefile` to compile the source files into an executable. The compilation process is simplified through the use of explicit compilation rules within the `Makefile`.

- **make**: compile client and server
- **make clean**: delete objects files
- **make fclean**: clear all data use during and for compilation

## Documentation

We use Doxygen to generate the documentation. To generate the documentation, you can use the following command:

```bash
doxygen Doxyfile
```

Once the documentation is generated, you can open the `docs/html/index.html` file.
