#include "coeffsK.h"

// ---------------------------------------------------------- //
//  Coefficient matrices for Kxx                              //
// ---------------------------------------------------------- //


// Range R0: ( 0.2 => lambda1 > 1 )
const double Kxx::A0[16][9] = {
	{ 2.131478068828, -0.23195525157, 0.088239553735, -0.189325902007, 0.070421448927, -0.044266506425, -0.036352182014, 0.017935197376, 0.000468101393,  },
	{ 5.11565944142, 0.059323564581, -0.204365396261, -1.050028463613, -0.373036001109, 0.140505561318, -0.009910074911, 0.139635176248, -0.017045751407,  },
	{ -1.845929116975, 0.140384251543, 0.681671527102, 1.19965924205, 0.513667755065, 0.078080642904, -0.40708034936, -0.287377263294, -0.153121392762,  },
	{ 0.118039750772, -0.226528936144, -0.626446241443, -0.00939154499, -0.009046071324, -0.225813450344, -0.010044668226, -0.008260603693, 0.251026740593,  },
	{ 2.780649914759, -0.199144596037, -0.294842316174, -1.042995351428, 0.251891230305, 0.212789474357, 0.251017316099, -0.23808710209, -0.026047372518,  },
	{ 0.8590075928, -1.553914312507, -0.018303947749, -1.193617333182, -0.24366457102, -0.300505002447, 0.566871139982, 0.352740476884, 0.144800615838,  },
	{ -0.822835588722, 0.148717847484, 0.5218088709, -0.34943008796, -0.386021586553, -0.065610877084, 0.363260973521, 0.254334129606, -0.085961855993,  },
	{ 0.942291998383, 0.254634654968, 0.216591766582, -0.770109094805, -0.341122709117, -0.034529684105, 0.35743000299, 0.157295089852, -0.02690639408,  },
	{ -0.982329138178, 0.193764460132, 0.669541360059, 0.845521013254, -0.225578112285, -0.438798230404, -0.396500211512, 0.320221165707, 0.058993337276,  },
	{ -0.604059586209, -0.057034084649, -0.643237849126, 1.107592260848, 1.091504860735, 0.395917062597, -0.648292035038, -0.640677847231, -0.093802101797,  },
	{ -0.070034296199, 0.822475141257, -0.607771481214, 0.384293397285, 0.068056376091, 0.3516710514, -0.229633761424, -0.159319743207, -0.088422480433,  },
	{ 0.460081054453, 0.230908201204, 0.090429138927, 0.049256332481, 0.229879837426, 0.254328793531, -0.104001810753, -0.177927086017, -0.149620140902,  },
	{ 0.309364275098, -0.013279755487, -0.404028688054, -0.347340327093, -0.057404648717, 0.277976807177, 0.193851959526, -0.081812839063, -0.046969650254,  },
	{ 0.176347341549, 0.056251712658, 0.780229054566, -0.336118420474, -0.04971348182, -0.291992608011, 0.246735376443, 0.01696269427, 0.031835515374,  },
	{ 0.412440550472, 0.166686104542, -0.471251621973, -0.346089872934, -0.707539531903, -0.260235571704, 0.163686377083, 0.396532473375, 0.217349388305,  },
	{ -0.721414116876, -0.76975723074, 0.302865357987, 0.439656395176, 0.318687966867, -0.04209483582, -0.200355636358, -0.061771950632, -0.026138838923,  }
};

// Range R1: ( 1 => lambda1 => 5 )
const double Kxx::A1[16][9] = {
	{ 3.533499208373, -0.339279019842, 0.045680830827, -0.690010767082, 0.045833707295, 0.014740884177, 0.0214665152, 0.015571300899, -0.011726869353,  },
	{ 2.315806067923, -0.235219690477, 0.051122341843, -0.471982625201, 0.075787893482, -0.004274897106, 0.039129889679, -0.016889215426, -0.001661681867,  },
	{ 0.659175199052, -0.042160794228, 0.048908636928, -0.112802922996, -0.023956732281, 0.01667266081, 0.014439535836, 0.011523987571, -0.012095945087,  },
	{ -0.183284328465, 0.008196817133, -0.002783544627, 0.029754966866, -0.028791175025, 7.7613088e-05, -0.005755127095, 0.016836391344, -0.003150436534,  },
	{ 1.761875342429, -0.266778718149, -0.047549422678, -0.326034468164, -0.01183231756, 0.006692575366, -0.015530106917, 0.028824296232, 0.00148807504,  },
	{ 0.693606864031, -0.203544608422, -0.029694929667, -0.188338631998, 0.142230961021, -0.051245785824, 0.04194048461, -0.065005185925, 0.031070235524,  },
	{ -0.535109290642, 0.036074872652, -0.003586873413, 0.144884391165, -0.050666302874, 0.01326848845, -0.009031760054, 0.011277224109, -0.003192502301,  },
	{ 0.122629449748, 0.00284662833, -0.003648387487, -0.025522867223, 0.033847989209, -0.006501108372, 0.004082472563, -0.015395414233, 0.004059330143,  },
	{ -0.168238671179, 0.105589926311, 0.025205401695, 0.099165191766, -0.151708558651, 0.060409232875, -0.028096143986, 0.06908260352, -0.034365932504,  },
	{ 0.017579089037, -0.083705235778, 0.005624790965, -0.117208308186, 0.239996619797, -0.081598072265, 0.081168055215, -0.118112242978, 0.039941589602,  },
	{ 0.057340131798, 0.04862090463, -0.005865692879, 0.049877656218, -0.121301318808, 0.039558248671, -0.043916950863, 0.064922477031, -0.021131076198,  },
	{ -0.019136016757, -0.009653231889, 0.002383860827, -0.0061800185, 0.010125306865, -0.003806560048, 0.005516527204, -0.005955441911, 0.002027216734,  },
	{ 0.017637290316, -0.014237557379, -0.002407778517, -0.016456937935, 0.029719333386, -0.011110252274, 0.007150382503, -0.014589791252, 0.006234513571,  },
	{ -0.014565941831, 0.017587993336, -0.000450572126, 0.028592396362, -0.049299823508, 0.015864495822, -0.016799122932, 0.024633873208, -0.008126008421,  },
	{ 0.00180926225, -0.009462542543, 0.000953212274, -0.014024249981, 0.025101508775, -0.007764682388, 0.008845849287, -0.013016392671, 0.004094017999,  },
	{ 0.000568560559, 0.001666346932, -0.000311398688, 0.001980707221, -0.003053759447, 0.00095164608, -0.00121780371, 0.001636800856, -0.000512564713,  }
};

// Range R2: ( 5 > lambda1 => 11 )
const double Kxx::A2[16][9] = {
	{ -1.489745612103, 2.399189836678, 0.139992642908, 6.754744535664, 1.713574032167, -4.288286603774, -3.355685745719, -1.606035592576, 2.604474709224,  },
	{ 9.752494737941, -6.778672090694, 0.678923282231, -11.024600562067, 3.71358713271, 3.012983361227, 4.401364171735, -0.196630698194, -2.298341984747,  },
	{ -2.571731549403, 2.879610885496, -0.51465249241, 4.043691157844, -3.220680638111, 0.029165149973, -1.694819662472, 1.094282869211, 0.209471309877,  },
	{ 0.289605985695, -0.360936340679, 0.088560479667, -0.4714940674, 0.521531167291, -0.11098933873, 0.201368516111, -0.20324690296, 0.030872823684,  },
	{ 3.210721028453, -0.707355051365, -0.179513249391, -2.645581990937, -1.628424674153, 2.086434356414, 1.103069583231, 0.997776868674, -1.162898095214,  },
	{ -1.809220637962, 1.585363631404, -0.06247787989, 3.202478560293, -0.026448593602, -1.703654359448, -1.3334721666, -0.437861380974, 1.079257157155,  },
	{ 0.713684456437, -0.809234824799, 0.127381271371, -1.242647695282, 0.753512419936, 0.173552435007, 0.531885558171, -0.237470143342, -0.148677735136,  },
	{ -0.086469833297, 0.109291437774, -0.026206285314, 0.149842549405, -0.151469905971, 0.024077078742, -0.064885112874, 0.059221140233, -0.004940360669,  },
	{ -0.217720839374, 0.025149149227, 0.045154520291, 0.243071473519, 0.31696795068, -0.308159631932, -0.106776172394, -0.168717172127, 0.161901194072,  },
	{ 0.199817191732, -0.136427657255, -0.015353336071, -0.314160901604, -0.129278722105, 0.263930002024, 0.132468212818, 0.104515180543, -0.152253796514,  },
	{ -0.073344187489, 0.076516584488, -0.008484011163, 0.125451810366, -0.047947380106, -0.038704991477, -0.054224805091, 0.011909380281, 0.024647475958,  },
	{ 0.008950573017, -0.011021535391, 0.002488496012, -0.015635519967, 0.014173782541, -0.001269027979, 0.006822130277, -0.005536878132, -2.2358245e-05,  },
	{ 0.007253853714, 0.00108252288, -0.002665926517, -0.007235755706, -0.01707499643, 0.014222681728, 0.003245410063, 0.008489485288, -0.007188633298,  },
	{ -0.006999343811, 0.003286485751, 0.001458719914, 0.009918666429, 0.009802744927, -0.012428235749, -0.004196907343, -0.005950320768, 0.00675055278,  },
	{ 0.002515651885, -0.002315441521, 8.9415863e-05, -0.004125844095, 0.000441399157, 0.002109823103, 0.001793402796, 9.7741346e-05, -0.001188430814,  },
	{ -0.000309729984, 0.000365058662, -7.5291081e-05, 0.000535610891, -0.0004238985, -2.331608e-06, -0.000234821936, 0.000164976045, 2.0473e-05,  }
};


// ---------------------------------------------------------- //
//  Coefficient matrices for Kyy                              //
// ---------------------------------------------------------- //


// Range R0: ( 0.2 => lambda1 > 1 )
const double Kyy::A0[16][9] = {
	{ 2.102285823445, -0.237240456402, 0.081481303118, -0.189185424724, 0.078114786862, -0.046809808171, -0.031524999098, 0.011304984699, 0.00138602914,  },
	{ 2.482648092553, -0.105133756758, -0.376609847748, -0.89730060753, -0.319920476308, 0.180079820639, 0.163195931618, 0.110661177452, -0.001641119929,  },
	{ -0.101434189024, 0.553143535167, 0.298848261808, 1.127577450603, 1.061150205076, -0.342481543971, -0.73247118227, -0.32638983609, -0.06069442755,  },
	{ -0.36218187589, -0.153819564589, -0.299875087752, -0.071546898653, -0.243903153305, -0.048058513476, 0.281304225381, -0.243089523632, 0.405809047874,  },
	{ 5.717897914883, 0.042605227621, -0.050941135468, -1.190005622853, 0.123627005691, 0.189692766129, 0.040300526789, -0.177243806909, -0.030497319933,  },
	{ -0.127965227338, -2.089626866433, 0.473993836485, -1.133840644098, -0.903733389695, 0.204518658648, 0.737041745827, 0.52134588207, -0.080903682009,  },
	{ -0.599321412662, -0.376285095764, 0.429018719987, -0.482311351014, -0.147257513554, -0.064055869192, 0.268959510758, 0.434511545126, -0.315900704077,  },
	{ 0.090183512831, -0.052666892955, 0.118558913321, -0.718267477353, -0.515449888723, 0.163710724964, 0.376702183099, 0.351232792439, -0.244789913108,  },
	{ -2.808695700703, -0.075790085033, 0.314936814747, 0.799334952325, 0.194588361798, -0.578863420187, -0.132600479571, 0.161473582189, 0.097353644039,  },
	{ 0.47852445531, 1.020598721278, -0.632211744683, 1.421679719032, 0.807773272564, 0.177433584936, -0.853879623263, -0.756455432857, 0.24736735887,  },
	{ 0.64245850405, 1.050040087038, -0.617041243564, 0.347644367129, 0.369992139481, 0.084836463044, -0.29359808049, -0.285124510351, 0.105974441487,  },
	{ 0.685447699571, 0.54758319312, -0.118248678549, 0.231851664871, 0.091193097501, 0.219053971135, -0.292459794691, -0.037022811271, -0.178997019622,  },
	{ 0.987516195089, 0.1003087108, -0.264162569462, -0.32268232227, -0.317792356137, 0.414352476463, 0.08956082885, 0.020972281419, -0.084816942732,  },
	{ -0.180676542475, -0.216070328401, 0.581773843375, -0.398638493735, 0.065186863265, -0.271568131305, 0.227666540962, 0.123585569474, -0.16252365503,  },
	{ -0.436048732, -0.472615039539, -0.149292025187, -0.674360261669, -0.330186355428, -0.25460926954, 0.548915186225, 0.11829585296, 0.304716949496,  },
	{ -0.31105354618, -0.516494628408, 0.292577359511, 0.539482748551, 0.14174625607, -0.02170565253, -0.295338904364, -0.029466299469, -0.010628008898,  }
};

// Range R1: ( 1 => lambda1 => 5 )
const double Kyy::A1[16][9] = {
	{ 3.213434064152, -0.33659542164, 0.004320601021, -0.648050006121, 0.055520237543, 0.018860159112, 0.011562429136, 0.01658400423, -0.009681110948,  },
	{ 1.713691776679, -0.21289724346, -0.035698033108, -0.370764751967, 0.064603034927, 0.016636085299, 0.007226727403, 0.000508097381, -0.003986091401,  },
	{ 0.029623936224, 0.042283542195, -0.092895038136, 0.018010685052, -0.129432700052, 0.108525959085, -0.033476005929, 0.079957210864, -0.048121284979,  },
	{ 0.071656303776, -0.075823569749, 0.069741726816, -0.125380582747, 0.103786612222, -0.047873338681, 0.073928902873, -0.048638585586, 0.010832319033,  },
	{ 2.909653437023, -0.356394537833, 0.158104312799, -0.543653399909, 0.075789184098, -0.078161523556, 0.060713889382, -0.038548877007, 0.026357115095,  },
	{ 1.116129374274, -0.302743463246, 0.108915002685, -0.278659905602, 0.26851883028, -0.161819551093, 0.076353014168, -0.140197534595, 0.078053537399,  },
	{ -0.594731665974, 0.124329768153, -0.063776300607, 0.245823579134, -0.197721489665, 0.08754457544, -0.064768472967, 0.085053437021, -0.034932714407,  },
	{ 0.03457567063, 0.027310574509, -0.021227050239, 0.038429871469, -0.000547535114, -0.007134044811, -0.029629197719, -0.001338234349, 0.009171384001,  },
	{ -0.141289101546, 0.275058410413, -0.109529184465, 0.192172779317, -0.402228258696, 0.222897077227, -0.085862417907, 0.195972006658, -0.108176973722,  },
	{ -0.283975300482, -0.196819507599, 0.059012207976, -0.133419131029, 0.431731111436, -0.207327278753, 0.103076555865, -0.212038773164, 0.102626224931,  },
	{ 0.196218992438, 0.054595905764, -0.002748791658, 0.008709434529, -0.137413795207, 0.063972999101, -0.025616918138, 0.073271183998, -0.036153005403,  },
	{ -0.019440155811, -0.01493564653, 0.004825372245, -0.01463665467, 0.018004214608, -0.005344341397, 0.010427385185, -0.009025049011, 0.002061830586,  },
	{ 0.008863015481, -0.040603041819, 0.016128774345, -0.028641390025, 0.072025919663, -0.038121638064, 0.014968007703, -0.036427542376, 0.019315144878,  },
	{ 0.022505601595, 0.041536641159, -0.013857251028, 0.033872059441, -0.091343718544, 0.043517665198, -0.021520352484, 0.046212746858, -0.022154726762,  },
	{ -0.017602071853, -0.014296825175, 0.00315499982, -0.010387563076, 0.034948974353, -0.015901358538, 0.00755333472, -0.018240782972, 0.008580388689,  },
	{ 0.002049560782, 0.002370291997, -0.000614186717, 0.002304248145, -0.004311334839, 0.001630619935, -0.001465268907, 0.002219669325, -0.000829981074,  }
};

// Range R2: ( 5 > lambda1 => 11 )
const double Kyy::A2[16][9] = {
	{ -0.30069240993, 0.618727333196, 1.124911442775, 6.74183021527, 1.877969555326, -3.724284987598, -3.887228678809, -0.009908425524, 1.257384381113,  },
	{ 7.6335782273, -5.645381202315, -0.088197604369, -10.863843079125, 3.81278837662, 2.832214049259, 4.876479680242, -1.572475435973, -1.4436582531,  },
	{ -2.044222280068, 2.407389275479, -0.270937783846, 3.712554271202, -2.686644604653, -0.213373831593, -1.655251376057, 1.190908365355, 0.142338382936,  },
	{ 0.234347099293, -0.316741237536, 0.069242030217, -0.438774217344, 0.464760572331, -0.083871142425, 0.194458944044, -0.205281275696, 0.031469839135,  },
	{ 3.970413881376, 0.121275423613, -0.549588123404, -2.662353828436, -1.90388860003, 1.971831262784, 1.271903971621, 0.456814124766, -0.690852963088,  },
	{ -1.57377543205, 1.059939823298, 0.289676816445, 3.136661787669, -0.029551963867, -1.678273601306, -1.495208178217, 0.071068276719, 0.766305999784,  },
	{ 0.583790304389, -0.62296651513, 0.014571111044, -1.117707477562, 0.580749998391, 0.26208350392, 0.516366451906, -0.283012600845, -0.119478674787,  },
	{ -0.071668107233, 0.093168969978, -0.017553304632, 0.138056456359, -0.134423226582, 0.015196826495, -0.062485628647, 0.061414475008, -0.005950527489,  },
	{ -0.212603025438, -0.07365226935, 0.088641318494, 0.231157989051, 0.357043971421, -0.298043268783, -0.125913831038, -0.108380856525, 0.107518015036,  },
	{ 0.173065594221, -0.068402890776, -0.05762995183, -0.303030637973, -0.136779991156, 0.264301784651, 0.151270267861, 0.048339156695, -0.117314515065,  },
	{ -0.059607222102, 0.053393078445, 0.005694833023, 0.110170507992, -0.027248410483, -0.049637704564, -0.052344244984, 0.016751631921, 0.021530720231,  },
	{ 0.007450730613, -0.009103262698, 0.001391792416, -0.014246515381, 0.012312964554, -0.000257314633, 0.006548464735, -0.005818140316, 0.000107904263,  },
	{ 0.006636733846, 0.005169315055, -0.004449579957, -0.006419060314, -0.01934238621, 0.01422955191, 0.003876359369, 0.00648242805, -0.005282757279,  },
	{ -0.005914226947, 0.000479416546, 0.003118336734, 0.00932400507, 0.010461168989, -0.012648231418, -0.004876970085, -0.003978761633, 0.005530471937,  },
	{ 0.002004052397, -0.001394307367, -0.000471130382, -0.00351107778, -0.000392596621, 0.00255961343, 0.001714152022, -5.5492572e-05, -0.001091075984,  },
	{ -0.000256736082, 0.000290867375, -3.1826942e-05, 0.000481624179, -0.000354557845, -4.113095e-05, -0.000224265294, 0.000175047695, 1.608235e-05,  }
};


// ---------------------------------------------------------- //
//  Coefficient matrices for Kzz                              //
// ---------------------------------------------------------- //


// Range R0: ( 0.2 => lambda1 > 1 )
const double Kzz::A0[16][9] = {
	{ 1.331926935196, -0.177152725796, 0.063609977724, -0.175017999795, 0.05601661288, -0.023698416199, -0.009037732158, 0.008605650088, -0.00184940684,  },
	{ 3.937807938427, -0.0154733975, -0.323837781204, -1.060521060071, -0.097278054628, 0.093472462237, 0.087955852199, -0.023818258033, 0.023430325691,  },
	{ -1.52482369578, 0.109377496329, 0.669401177768, 0.714949168518, 0.256300640626, -0.25320552538, -0.027494532825, -0.08868280037, -0.001482816052,  },
	{ 0.288967928389, -0.027737791316, -0.613533651225, 0.436905861398, 0.101293065173, 0.03716802922, -0.257854002192, 0.020922439495, 0.079134961834,  },
	{ 4.052788390821, -0.098380714736, -0.156688220097, -1.105871373193, 0.035504204562, 0.109129959421, 0.124102212614, -0.03774769427, -0.020779464864,  },
	{ 1.933152387806, -1.557434763503, -0.059245417434, -0.690798553081, -0.377407158309, 0.32969484483, 0.163394556018, 0.31592865735, -0.157696951479,  },
	{ -0.737820000861, -0.199815996685, 0.500680974785, -0.162583287898, -0.268277030306, 0.01401301534, 0.137834469928, 0.076051903999, -0.074670961672,  },
	{ 0.488151222777, 0.068881379291, 0.149501742715, -0.66743123091, -0.406876193667, 0.163407317273, 0.205519848972, 0.027590938444, -0.062710655468,  },
	{ -1.790133353355, -0.141279305763, 0.505554116683, 0.844878036785, 0.235127595668, -0.387928623434, -0.14283792032, -0.13099132663, 0.130324275788,  },
	{ -0.179113700051, 0.576698039065, -0.526884103698, 0.426644608546, 0.578835489903, -0.105515324828, 0.008270605794, -0.162006216935, 0.059163710441,  },
	{ -0.311804508249, 0.950797705097, -0.479646775742, 0.30490148192, 0.349386121375, -0.140448085612, -0.119928265767, -0.12481598733, 0.098191181571,  },
	{ 0.241284883976, 0.336521676554, 0.084682929284, -0.379665165272, -0.077653501988, 0.068210039679, 0.185065399521, -0.039069108875, -0.049688823506,  },
	{ 0.638693028617, 0.167200531981, -0.341768416676, -0.292579730047, -0.261393682411, 0.283153847033, 0.044503079608, 0.15007516684, -0.104018453408,  },
	{ -0.104287759042, -0.277651941242, 0.678423243644, -0.378421709042, -0.218333043976, -0.047646396354, 0.18465074626, -0.108306557275, -0.006628631399,  },
	{ 0.195326792443, -0.072145403348, -0.428486475302, 0.410665500978, 0.166512469516, -0.131084865456, -0.352266658943, 0.015285828347, 0.137924440291,  },
	{ -0.192363997015, -0.637986950214, 0.274280276348, 0.146802670446, 0.029201866813, 0.024214621808, 0.024365813881, 0.093767933617, -0.069309351503,  }
};

// Range R1: ( 1 => lambda1 => 5 )
const double Kzz::A1[16][9] = {
	{ 2.925422131802, -0.298029955439, -0.00881562864, -0.701232833172, 0.03073412947, 0.03953220447, 0.044604613669, 0.030583249469, -0.027096804636,  },
	{ 1.766353516224, -0.197706556164, -0.012750565009, -0.401404601432, 0.031396761327, 0.028112032006, 0.013069489177, 0.017352218054, -0.016104536202,  },
	{ 0.264638704145, 0.044885160055, -0.0394463875, 0.087520838998, -0.26415032325, 0.137914877799, -0.097791854676, 0.146736111509, -0.066499005547,  },
	{ 0.08924706806, -0.073694785065, 0.038926274697, -0.207395216574, 0.179149596717, -0.069835657582, 0.146387949395, -0.100746767392, 0.027749262368,  },
	{ 2.566130161123, -0.35829063428, 0.035442053723, -0.564542941647, 0.151568659761, -0.085863840126, 0.184519990248, -0.100895263506, 0.043955791794,  },
	{ 1.304477622015, -0.333349574907, 0.046378034881, -0.346514231449, 0.411585093518, -0.202239523898, 0.190786951474, -0.23296968544, 0.108195661391,  },
	{ -0.367826074703, 0.107612270642, -0.04383652071, 0.395847313564, -0.336206755268, 0.11744348922, -0.141052152156, 0.151010453081, -0.046647144731,  },
	{ -0.052249136457, 0.024772734751, -0.009229169212, 0.045912198445, 0.003657572101, -0.00392525666, -0.053441122699, 0.011092884505, 0.001266681942,  },
	{ -0.288480441681, 0.257272338743, -0.064335343764, 0.357886032566, -0.603042783226, 0.276778875618, -0.204771255606, 0.313758429422, -0.141824081075,  },
	{ 0.04461976845, -0.23318047441, 0.065025571467, -0.319964264146, 0.671255939041, -0.278556201088, 0.209090042463, -0.331200608865, 0.134831955896,  },
	{ -0.02376411988, 0.087166186251, -0.015261079046, 0.046957691767, -0.203721327143, 0.087113064919, -0.054260062518, 0.10861498873, -0.04747657645,  },
	{ 0.026374573242, -0.018445981392, 0.00396133217, -0.02202469567, 0.025683990902, -0.009155662334, 0.019980712937, -0.017165340244, 0.005663282725,  },
	{ 0.035474107106, -0.040417738954, 0.011652659462, -0.058840446189, 0.107505738213, -0.047801774545, 0.0348754842, -0.056123550095, 0.024614128157,  },
	{ -0.030003086935, 0.04933026346, -0.014101406955, 0.075449751859, -0.141270326048, 0.057567333635, -0.046308220628, 0.071458243428, -0.028531689887,  },
	{ 0.013134479135, -0.020194051252, 0.00479889439, -0.024662368154, 0.053673671833, -0.021444306954, 0.0165161913, -0.027876330048, 0.011148299365,  },
	{ -0.003627674175, 0.003172688685, -0.000711020647, 0.004163943216, -0.006548397866, 0.002406912441, -0.002986179175, 0.003732796954, -0.001349786881,  }
};

// Range R2: ( 5 > lambda1 => 11 )
const double Kzz::A2[16][9] = {
	{ -3.139994271503, 2.016246661474, 1.139101897238, 10.85675962204, 1.630879996177, -6.289466532283, -5.876126664176, -1.22925173736, 3.626334262718,  },
	{ 10.835932884969, -6.972758941508, -0.036794044988, -15.423752021248, 4.424300749013, 5.035659787234, 7.211095582566, -0.542303755068, -3.709618047864,  },
	{ -2.94431606308, 3.060260059239, -0.417315292715, 5.396801485945, -4.039342640772, -0.228032551911, -2.577431345773, 1.635256347768, 0.403972781985,  },
	{ 0.351530454381, -0.417067093489, 0.097862871491, -0.638982222659, 0.709718958283, -0.143444366312, 0.308201089887, -0.311281360663, 0.041936181964,  },
	{ 4.183712778447, -0.334877607738, -0.667368353616, -3.973130842032, -2.252774522202, 3.14447848246, 1.97599354663, 1.095881981499, -1.657371511345,  },
	{ -1.77488254915, 1.348113125604, 0.314581481195, 4.570590035673, 0.39031836078, -2.792598143279, -2.157102199051, -0.597918879998, 1.727160296569,  },
	{ 0.756293764928, -0.789608868559, 0.051206971079, -1.624718383109, 0.837135225439, 0.371032264021, 0.781789194761, -0.342515955276, -0.257877746547,  },
	{ -0.100553578984, 0.121972524452, -0.026117164202, 0.199858155463, -0.20070945395, 0.027157243533, -0.096857703241, 0.090210872585, -0.005779742525,  },
	{ -0.246570348828, -0.045541586398, 0.113443872724, 0.369974787641, 0.444033941424, -0.45991010308, -0.196048603735, -0.199815090716, 0.228446070717,  },
	{ 0.201579718887, -0.086068295555, -0.071188684178, -0.43472475786, -0.243121909362, 0.420876885388, 0.209608736376, 0.150195962093, -0.238728523459,  },
	{ -0.074481659133, 0.066690751285, 0.003948463242, 0.157824498999, -0.037504381378, -0.07058071858, -0.076931824671, 0.015516035685, 0.040628983932,  },
	{ 0.010089925057, -0.011825220894, 0.00218025775, -0.020385766028, 0.018175495236, -0.000894453459, 0.009944860167, -0.008396877334, -0.000191319181,  },
	{ 0.007950873876, 0.004727711151, -0.005722351562, -0.010978407955, -0.024258909188, 0.021115700191, 0.006181974183, 0.010600919711, -0.010123161189,  },
	{ -0.006885256798, 0.000496324286, 0.003986796284, 0.013216547255, 0.016513457907, -0.019449526293, -0.006539845043, -0.008670974874, 0.010426785372,  },
	{ 0.002441944027, -0.001687322636, -0.000495719849, -0.004955671662, -0.000642283524, 0.003608830548, 0.002455902878, 0.00025384944, -0.00190143909,  },
	{ -0.000339385612, 0.000374049303, -5.4462385e-05, 0.000681160445, -0.00051954412, -3.9259159e-05, -0.000334830349, 0.000249140147, 3.5155961e-05,  }
};
