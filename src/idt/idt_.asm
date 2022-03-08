global idt_loader
extern idtp
%assign vector 0
extern exception_handler

idt_loader:  
    lidt [idtp]
    ret
