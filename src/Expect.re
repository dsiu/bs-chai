type chai;

module Expect = {
  [@bs.module "chai"] external expect : 'a => chai = "";
};

module Chains = {
  [@bs.get] external to_ : chai => chai = "to";
  [@bs.get] external be : chai => chai = "";
  [@bs.get] external been : chai => chai = "";
  [@bs.get] external is : chai => chai = "";
  [@bs.get] external that : chai => chai = "";
  [@bs.get] external which : chai => chai = "";
  [@bs.get] external and_ : chai => chai = "and";
  [@bs.get] external has : chai => chai = "";
  [@bs.get] external have : chai => chai = "";
  [@bs.get] external with_ : chai => chai = "with";
  [@bs.get] external at : chai => chai = "";
  [@bs.get] external of_ : chai => chai = "of";
  [@bs.get] external same : chai => chai = "";
  [@bs.get] external but : chai => chai = "";
  [@bs.get] external does : chai => chai = "";
};

module Modifiers = {
  [@bs.get] external not : chai => chai = "";
  [@bs.get] external deep : chai => chai = "";
  [@bs.get] external nested : chai => chai = "";
  [@bs.get] external own : chai => chai = "";
  [@bs.get] external ordered : chai => chai = "";
  [@bs.get] external any : chai => chai = "";
  [@bs.get] external all : chai => chai = "";
  [@bs.get] external itself : chai => chai = "";
  [@bs.get] external include_ : chai => chai = "include";
};

module Comparisons = {
  module Internal = {
    type constructor;
    [@bs.send.pipe: chai] external a : (string, ~msg:string=?, unit) => chai = "a";
    [@bs.send.pipe: chai] external include_ : ('a, ~msg:string=?, unit) => chai = "include";
    [@bs.send.pipe: chai] external equal : ('a, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external eql : (Js.t('a), ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external above : (float, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external below : (float, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external least : (float, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external most : (float, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external within : (float, float, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external instanceof : (constructor, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external property : (string, ~value:'a=?, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external ownPropertyDescriptor : (string, ~descriptor:Js.t('a)=?, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external lengthOf : (int, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external match_ : (Js.Re.t, ~msg:string=?, unit) => chai = "match";
    [@bs.send.pipe: chai] external string_ : (string, ~msg:string=?, unit) => chai = "string";
    [@bs.send.pipe: chai] external respondTo : (string, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external closeTo : (float, ~delta:float, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external members : (array('a), ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external oneOf : (array('a), ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external change : (array('a), ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external increase : (Js.t('a), string, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external decrease : (Js.t('a), string, ~msg:string=?, unit) => chai = "";
    [@bs.send.pipe: chai] external by : (float, ~msg:string=?, unit) => chai = "";
  };

  [@bs.get] external ok : chai => chai = "ok";
  [@bs.get] external true_ : chai => chai = "true";
  [@bs.get] external false_ : chai => chai = "false";
  [@bs.get] external null : chai => chai = "";
  [@bs.get] external undefined : chai => chai = "";
  [@bs.get] external nan : chai => chai = "NaN";
  [@bs.get] external exist : chai => chai = "";
  [@bs.get] external empty : chai => chai = "";
  [@bs.get] external arguments : chai => chai = "";
  [@bs.get] external extensible : chai => chai = "";
  [@bs.get] external sealed : chai => chai = "";
  [@bs.get] external frozen : chai => chai = "";
  [@bs.get] external finite : chai => chai = "";

  [@bs.send.pipe: chai] external keys : array(string) => chai = "keys";
  [@bs.send.pipe: chai] external keys' : array(int) => chai = "keys";
  [@bs.send.pipe: chai] external keys'' : Js.t('a) => chai = "keys";
  [@bs.send.pipe: chai]
  external throw : (~error:Js.Exn.t=?, ~matcher:Js.Re.t=?, ~msg:string=?, unit) => chai = "";

  /* Provides a better ordering for optional args to avoid the () */
  let a = (~msg=?, value) => Internal.a(value, ~msg=?, ());
  let include_ = (~msg=?, value) => Internal.include_(value, ~msg=?, ());
  let equal = (~msg=?, value) => Internal.equal(value, ~msg=?, ());
  let eql = (~msg=?, value) => Internal.eql(value, ~msg=?, ());
  let above = (~msg=?, value) => Internal.above(value, ~msg=?, ());
  let below = (~msg=?, value) => Internal.below(value, ~msg=?, ());
  let least = (~msg=?, value) => Internal.least(value, ~msg=?, ());
  let most = (~msg=?, value) => Internal.most(value, ~msg=?, ());
  let within = (~msg=?, min, max) => Internal.within(min, max, ~msg=?, ());
  let instanceof = (~msg=?, value) => Internal.instanceof(value, ~msg=?, ());
  let property = (~msg=?, ~value=?, name) => Internal.property(name, ~value=?, ~msg=?, ());
  let ownPropertyDescriptor = (~msg=?, ~descriptor=?, name) => Internal.ownPropertyDescriptor(name, ~descriptor=?, ~msg=?, ());
  let lengthOf = (~msg=?, value) => Internal.lengthOf(value, ~msg=?, ());
  let match_ = (~msg=?, value) => Internal.match(value, ~msg=?, ());
  let string_ = (~msg=?, value) => Internal.string_(value, ~msg=?, ());
  let respondTo = (~msg=?, value) => Internal.respondTo(value, ~msg=?, ());
  let closeTo = (~msg=?, value, ~delta) => Internal.closeTo(value, ~delta, ~msg=?, ());
  let members = (~msg=?, value) => Internal.members(value, ~msg=?, ());
  let oneOf = (~msg=?, value) => Internal.oneOf(value, ~msg=?, ());
  let change = (~msg=?, value) => Internal.change(value, ~msg=?, ());
  let increase = (~msg=?, obj, prop) => Internal.increase(obj, prop, ~msg=?, ());
  let decrease = (~msg=?, obj, prop) => Internal.decrease(obj, prop, ~msg=?, ());
  let by = (~msg=?, value) => Internal.by(value, ~msg=?, ());
};

module Combos = {
  /* Some sugar to avoid the boilerplate of piping to much */
  let to_deep_equal = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Modifiers.deep |> Comparisons.equal(~msg=?, value);
  let to_be = to_deep_equal;
  let to_be_a = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.a(~msg=?, value);
  let to_be_ok = chai =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.ok;
  let to_include = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Comparisons.include_(~msg=?, value);
  let to_equal = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Comparisons.equal(~msg=?, value);
  let to_eql = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Comparisons.eql(~msg=?, value);
  let to_be_above = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.above(~msg=?, value);
  let to_be_below = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.below(~msg=?, value);
  let to_be_at_least = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.least(~msg=?, value);
  let to_be_at_most = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.most(~msg=?, value);
  let to_be_within = (~msg=?, min, max, chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.within(~msg=?, min, max);
  let to_be_instanceof = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.instanceof(~msg=?, value);
  let to_have_property = (~msg=?, ~value=?, name, chai) =>
    chai |> Chains.to_ |> Chains.have |> Comparisons.property(~msg=?, ~value=?, name);
  let to_have_own_property_descriptor = (~msg=?, ~descriptor=?, name, chai) =>
    chai |> Chains.to_ |> Chains.have |> Comparisons.ownPropertyDescriptor(~msg=?, ~descriptor=?, name);
  let to_be_of_length = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.be |> Chains.of_ |> Comparisons.lengthOf(~msg=?, value);
  let to_match = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Comparisons.match_(~msg=?, value);
  let to_have_string = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.have |> Comparisons.string_(~msg=?, value);
  let to_throw = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Comparisons.throw(~msg=?, value);
  let to_respond_to = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Comparisons.respondTo(~msg=?, value);
  let to_be_close_to = (~msg=?, ~delta, value, chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.closeTo(~msg=?, ~delta, value);
  let to_have_members = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.have |> Comparisons.members(~msg=?, value);
  let to_be_one_of = (~msg=?, value, chai) =>
    chai |> Chains.to_ |> Chains.have |> Comparisons.oneOf(~msg=?, value);
  let to_have_keys = (value, chai) =>
    chai |> Chains.to_ |> Chains.have |> Comparisons.keys(value);
  let to_be_true = (chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.true_;
  let to_be_false = (chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.false_;
  let to_be_null = (chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.null;
  let to_be_undefined = (chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.undefined;
  let to_be_NaN = (chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.nan;
  let to_exist = (chai) =>
    chai |> Chains.to_ |> Comparisons.exist;
  let to_be_empty = (chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.empty;
  let to_be_sealed = (chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.sealed;
  let to_be_frozen = (chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.frozen;
  let to_be_finite = (chai) =>
    chai |> Chains.to_ |> Chains.be |> Comparisons.finite;

  module End = {
    /* Sugar that ignores the result so you don't have to */
    let to_deep_equal = (~msg=?, value, chai) =>
      chai |> to_deep_equal(~msg=?, value) |> ignore;
    let to_be = (~msg=?, value, chai) =>
      chai |> to_be(~msg=?, value) |> ignore;
    let to_be_a = (~msg=?, value, chai) =>
      chai |> to_be_a(~msg=?, value) |> ignore;
    let to_be_ok = chai =>
      chai |> to_be_ok |> ignore;
    let to_include = (~msg=?, value, chai) =>
      chai |> to_include(~msg=?, value) |> ignore;
    let to_equal = (~msg=?, value, chai) =>
      chai |> to_equal(~msg=?, value) |> ignore;
    let to_eql = (~msg=?, value, chai) =>
      chai |> to_eql(~msg=?, value) |> ignore;
    let to_be_above = (~msg=?, value, chai) =>
      chai |> to_be_above(~msg=?, value) |> ignore;
    let to_be_below = (~msg=?, value, chai) =>
      chai |> to_be_below(~msg=?, value) |> ignore;
    let to_be_at_least = (~msg=?, value, chai) =>
      chai |> to_be_at_least(~msg=?, value) |> ignore;
    let to_be_at_most = (~msg=?, value, chai) =>
      chai |> to_be_at_most(~msg=?, value) |> ignore;
    let to_be_within = (~msg=?, min, max, chai) =>
      chai |> to_be_within(~msg=?, min, max) |> ignore;
    let to_be_instanceof = (~msg=?, value, chai) =>
      chai |> to_be_instanceof(~msg=?, value) |> ignore;
    let to_have_property = (~msg=?, ~value=?, name, chai) =>
      chai |> to_have_property(~msg=?, ~value=?, name) |> ignore;
    let to_have_own_property_descriptor = (~msg=?, ~descriptor=?, name, chai) =>
      chai |> to_have_own_property_descriptor(~msg=?, ~descriptor=?, name) |> ignore;
    let to_be_of_length = (~msg=?, value, chai) =>
      chai |> to_be_of_length(~msg=?, value) |> ignore;
    let to_match = (~msg=?, value, chai) =>
      chai |> to_match(~msg=?, value) |> ignore;
    let to_have_string = (~msg=?, value, chai) =>
      chai |> to_have_string(~msg=?, value) |> ignore;
    let to_throw = (~msg=?, value, chai) =>
      chai |> to_throw(~msg=?, value) |> ignore;
    let to_respond_to = (~msg=?, value, chai) =>
      chai |> to_respond_to(~msg=?, value) |> ignore;
    let to_be_close_to = (~msg=?, ~delta, value, chai) =>
      chai |> to_be_close_to(~msg=?, ~delta, value) |> ignore;
    let to_have_members = (~msg=?, value, chai) =>
      chai |> to_have_members(~msg=?, value) |> ignore;
    let to_be_one_of = (~msg=?, value, chai) =>
      chai |> to_be_one_of(~msg=?, value) |> ignore;
    let to_have_keys = (value, chai) =>
      chai |> to_have_keys(value) |> ignore;
    let to_be_true = (chai) =>
      chai |> to_be_true |> ignore;
    let to_be_false = (chai) =>
      chai |> to_be_false |> ignore;
    let to_be_null = (chai) =>
      chai |> to_be_null |> ignore;
    let to_be_undefined = (chai) =>
      chai |> to_be_undefined |> ignore;
    let to_be_NaN = (chai) =>
      chai |> to_be_NaN |> ignore;
    let to_exist = (chai) =>
      chai |> to_exist |> ignore;
    let to_be_empty = (chai) =>
      chai |> to_be_empty |> ignore;
    let to_be_sealed = (chai) =>
      chai |> to_be_sealed |> ignore;
    let to_be_frozen = (chai) =>
      chai |> to_be_frozen |> ignore;
    let to_be_finite = (chai) =>
      chai |> to_be_finite |> ignore;
  };
};
