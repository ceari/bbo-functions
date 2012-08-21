require(DEoptim)
require(DiceOptim)
set.seed(1)


f = function(x) {
    val = system(paste("/home/daniel/development/workspace/bbo/bbfunc 123", sample(1:100000, 1), "f110 5 1 1 1 1 1", x[1], x[2], x[3], x[4], x[5]), intern=T)
    return (as.double(strsplit(val, c(" "))[[1]][[1]]))
}

est.ras = DEoptim(f, lower=c(-5,-5,-5,-5,-5), upper=c(5,5,5,5,5), control=list(storepopfrom=1, itermax=10, trace=F))


print (est.ras$optim)